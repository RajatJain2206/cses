#include "bits/stdc++.h"
#define int long long
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
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
bool isSafe(vector<string>&board, int row, int col){
    if(board[row][col] == '*') return false;

    for(int i=col-1;i>=0;i--){
        if(board[row][i]=='q') return false;
    }

    int r = row-1 , c = col-1;
    while(r>=0 && c>=0){
        if(board[r][c] == 'q') return false;
        r--;
        c--;
    }

    int r2 = row+1, c2 = col-1;
    while(r2<8 && c2>=0){
        if(board[r2][c2] =='q') return false;
        r2++;
        c2--;
    }
    return true;
}

void countWays(vector<string>& board, int col, int &cnt){
    if(col==8){
        cnt++;
        return;
    }

    for(int row =0;row<8;row++){
        if(isSafe(board,row,col)){
            board[row][col] = 'q';
            countWays(board,col+1,cnt);
            board[row][col] = '.';
        }
    }
}


void solve(){
    vector<string>chessBoard(8);
    for(int i=0;i<8;i++){
        cin>>chessBoard[i];
    }

    int noOfWays = 0;
    int col = 0;
    countWays(chessBoard,col,noOfWays);

    cout<<noOfWays<<endl;


    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    solve();
    return 0;
}

    