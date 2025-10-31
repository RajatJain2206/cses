#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>>movieTimings(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        movieTimings[i] = {b,a};
    }

    sort(movieTimings.begin(), movieTimings.end());

    int ans = 0;
    int last_end = 0;
    for(int i=0;i<n;i++){
        if(movieTimings[i].second >= last_end){
            ans++;
            last_end = movieTimings[i].first;
        }
    }

    cout<<ans<<endl;
    return 0;
}

// O(nlogn)
// sort by end times . always choose a movie that starts after the last movie we watched and has the earliest ending time among all such movies.