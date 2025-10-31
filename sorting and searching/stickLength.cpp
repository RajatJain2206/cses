#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>stickLengths(n);
    for(auto &length : stickLengths) cin>>length;

    sort(stickLengths.begin(), stickLengths.end());

    int mid = stickLengths[n/2];
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(stickLengths[i] - mid);
    }

    cout<<ans<<endl;
    return 0;
}

// Bruteforce -> O(n*n)
// just calculate taking every stick in consideration and then take the minimum


// Optimal -> O(nlogn)
// just sort and get the middle stick and then calculate the ans;

// most optimal -> O(n)
// using nth element stl in C++ .
// it rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
// It does not sort the list, just that all the elements, which precede the nth element are not greater than it, and all the elements which succeed it are not less than it.

// nth_element(stickLengths.begin(), stickLengths.begin() + n / 2, stickLengths.end());