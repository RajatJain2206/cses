#include "bits/stdc++.h"
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())        
#define mxe(v)  *max_element(v.begin(),v.end())    
#define mne(v)  *min_element(v.begin(),v.end())    
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

// input/output operators
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }


void solve(){
    int n,m;
    cin>>n>>m;
    pair<int,int> start;
    vector<string> labyrinth(n);
    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));
    vector<vector<int>> playerTime(n, vector<int>(m, 1e9));
    
    queue<pair<int,int>> monsterQ, playerQ;

    for(int i=0;i<n;i++){
        cin >> labyrinth[i];
        for(int j=0;j<m;j++){
            if(labyrinth[i][j]=='A'){
                start = {i,j};
                playerTime[i][j] = 0;
            }
            if(labyrinth[i][j]=='M'){
                monsterTime[i][j] = 0;
                monsterQ.push({i,j});
            }
        }
    }

    int dirX[4] = {0,0,1,-1};
    int dirY[4] = {-1,1,0,0};
    char dir[4] = {'L','R','D','U'};

    // BFS for monsters
    while(!monsterQ.empty()){
        int r = monsterQ.front().first;
        int c = monsterQ.front().second;
        monsterQ.pop();
        for(int i=0;i<4;i++){
            int nr = r + dirX[i];
            int nc = c + dirY[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(labyrinth[nr][nc]=='#' || monsterTime[nr][nc] <= monsterTime[r][c]+1) continue;
            monsterTime[nr][nc] = monsterTime[r][c]+1;
            monsterQ.push({nr,nc});
        }
    }

    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    vector<vector<char>> move_from(n, vector<char>(m, 0));
    playerQ.push(start);

    auto border = [&](int r, int c) {
        return (r == 0 || r == n-1 || c == 0 || c == m-1);
    };

    if(border(start.first, start.second)){
        cout << "YES\n0\n";
        return;
    }

    pair<int,int> exit = {-1,-1};

    // BFS for player
    while(!playerQ.empty()){
        int r = playerQ.front().first;
        int c = playerQ.front().second;
        playerQ.pop();
        for(int i=0;i<4;i++){
            int nr = r + dirX[i];
            int nc = c + dirY[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
            if(labyrinth[nr][nc]=='#' || playerTime[nr][nc] != 1e9) continue;

            int time = playerTime[r][c]+1;
            if(time >= monsterTime[nr][nc]) continue;

            playerTime[nr][nc] = time;
            parent[nr][nc] = {r,c};
            move_from[nr][nc] = dir[i];
            playerQ.push({nr,nc});

            if(border(nr,nc)){
                exit = {nr,nc};
                break;
            }
        }
        if(exit.first != -1) break;
    }

    if(exit.first == -1){
        cout << "NO\n";
        return;
    }

    // Reconstruct path
    string path;
    for(auto cur = exit; parent[cur.first][cur.second].first != -1; ){
        path += move_from[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=1;
    //cin >> T; // Uncomment if multiple test cases
    while(T--){
        solve();
    }

    return 0;
}
