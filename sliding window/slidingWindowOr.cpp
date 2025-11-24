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

    vector<int>v(n),pref(n),suff(n);
    v[0]=x;
    for(int i=1;i<n;i++){
        v[i] = (a*v[i-1]+b)%c;
    }

    for(int i=0;i<n;i++){
        pref[i] = (i%k==0) ? v[i] : (pref[i-1] | v[i]);
    }
    
    for(int i=n-1;i>=0;i--){
        suff[i] = (i%k==k-1) ? v[i] : (suff[i+1] | v[i]);
    }

    int ans = 0;
    for(int i=0;i<=n-k;i++){
        int l = i;
        int r = i+k-1;
        int val = pref[r] | suff[l];
        ans^=val;
    }

    cout<<ans<<endl;

    return 0;
}