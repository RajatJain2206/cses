#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<int>v(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i] = (a*v[i-1]+b)%c;
    }

    int val = 0;
    int start = 0 , end = k-1;
    for(int i=start;i<=end;i++){
        val^=v[i];
    }
    int ans = val;

    while(end<n-1){
        end++;
        val^=v[start];
        val^=v[end];
        start++;
        ans^=val;
    }

    cout<<ans<<endl;
    return 0;
}