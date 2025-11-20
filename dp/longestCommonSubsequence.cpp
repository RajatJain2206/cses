#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int idx1 = 1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){
            if(a[idx1-1]==b[idx2-1]){
                dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            }
            else{
                dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
    }

    vector<int>ans;
    int i = n , j = m;
    
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(ans.begin(), ans.end()); 
    cout<<(int)ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}