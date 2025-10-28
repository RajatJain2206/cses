#include<bits/stdc++.h>
using namespace std;
int minimize(vector<int>&coins,int x,vector<int>&dp){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    if(dp[x]!=-1) return dp[x];
    int ans = INT_MAX;
    for(int coin : coins){
        int res = minimize(coins,x-coin,dp);
        if(res!=INT_MAX){
            ans = min(ans,res+1);
        }
    }
    return dp[x] = ans;
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
    int ans = minimize(coins,x,dp);
    cout<<(ans==INT_MAX ? -1 : ans)<<endl;

    return 0;
}