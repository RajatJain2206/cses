#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int countWays(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(grid[i][j] == '*') return 0;
    if(i==0 && j==0) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];

    int up = countWays(i-1,j,grid,dp);
    int left = countWays(i,j-1,grid,dp);

    return dp[i][j] = (up+left)%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(n,0));
    // cout<<countWays(n-1,n-1,grid,dp)<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                dp[i][j] = 0;
                continue;
            }

            if(i==0 && j==0){
                dp[i][j] = 1;
                continue;
            }

            if(i>0){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            }

            if(j>0){
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
    

    return 0;
}