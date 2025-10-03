#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string>grid;
vector<vector<bool>>visited;
vector<vector<pair<int,int>>>parent;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char dir[4] = {'R','L','D','U'};

bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#' && !visited[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++)cin>>grid[i];
    visited.assign(n,vector<bool>(m,false));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));

    pair<int,int>start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='B') end = {i,j};
        }
    }
    // abhi tak we created the graph and visited array and then parent to store path
    // then we got the starting and ending position
    // BFS starts from here
    queue<pair<int,int>>q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(x==end.first && y==end.second) break;

        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(nx,ny)){
                visited[nx][ny] = true;
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }

    if(!visited[end.first][end.second]){
        cout<<"NO\n";
        return 0;
    }

    string path;
    pair<int,int>curr = end;
    while(curr != start){
        pair<int,int> p = parent[curr.first][curr.second]; // we are getting the parent of curr
        for(int k=0;k<4;k++){
            if(p.first + dx[k] == curr.first && p.second + dy[k] == curr.second){
                path += dir[k];
                break;
            }
        }
        curr = p;

    }

    reverse(path.begin(), path.end());
    cout<<"YES\n";
    cout<<path.size()<<endl;
    cout<<path<<endl;
    return 0;
}