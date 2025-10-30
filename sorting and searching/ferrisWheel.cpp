#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<int>childWt(n);
    for(auto &wt : childWt) cin>>wt;

    sort(childWt.begin(),childWt.end());
    int ans = 0;
    int st = 0 , end = n-1;
    while(st<=end){
        if(childWt[st]+childWt[end]<=x){
            st++;
            end--;
            ans++;
        }
        else{
            end--;
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}

// 2,3,7,9
// 2,3,7 ans=1
// 