#include<bits/stdc++.h>
using namespace std;
int removeDigits(int n, vector<int>&dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

    int temp = n;
    int ans = INT_MAX;
    
    while(temp){
        int d = temp%10;
        temp = temp/10;
        if(d!=0){
            ans = min(ans,1+removeDigits(n-d,dp));
        }
    }
    return dp[n] = ans;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    int steps = removeDigits(n,dp);
    cout<<steps<<endl;
    return 0;
}

