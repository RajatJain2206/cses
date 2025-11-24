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

    deque<pair<int,int>>dq; // this will store the value with index

    int ans = 0;
    int prev = x;

    for(int i=0;i<n;i++){
        int curr;
        if(i==0){
            curr = prev;
        }
        else{
            curr = (a*prev+b)%c;
            prev = curr;
        }

        while(!dq.empty() && dq.back().first >= curr){
            dq.pop_back();
        }

        dq.push_back({curr,i});

        if(dq.front().second <= i-k){
            dq.pop_front();
        }

        if(i>=k-1){
            ans^=dq.front().first;
        }
    }

    cout<<ans<<endl;

    return 0;
}