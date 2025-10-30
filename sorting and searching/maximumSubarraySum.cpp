#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &a : a) cin>>a;

    int maxSum = a[0];
    int currSum = a[0];

    for(int i=1;i<n;i++){
        currSum = max(a[i],currSum+a[i]);
        maxSum = max(maxSum,currSum);
    }
    cout<<maxSum<<endl;
    return 0;
}