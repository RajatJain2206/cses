#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>>customers(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        mini = min(mini,a);
        maxi = max(maxi, b);
        customers[i] = {a,b};
    }
    vector<pair<int,int>>events;
    for(int i=0;i<n;i++){
        events.push_back({customers[i].first, 1});
        events.push_back({customers[i].second, -1});
    }

    sort(events.begin(), events.end());

    int curr = 0 , ans = 0;
    for(auto &e : events){
        curr += e.second;
        ans = max(ans,curr);
    }

    cout<<ans<<endl;

    return 0;
}


// creating events so that it's easier to know what's happening at any time