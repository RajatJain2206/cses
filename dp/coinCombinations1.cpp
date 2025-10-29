#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int countNumberofWays(int target, vector<int>&coins, vector<int>&dp){
    if(target==0) return 1;
    if(dp[target]!= -1) return dp[target];

    int ways = 0;
    for(int coin : coins){
        if(coin<=target){
            ways= (ways+countNumberofWays(target-coin, coins, dp))%MOD;
        }
    }
    return dp[target] = (int)ways%MOD;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<int>dp(x+1,-1);
    int ans = countNumberofWays(x,coins,dp);
    cout<<ans<<endl;
}