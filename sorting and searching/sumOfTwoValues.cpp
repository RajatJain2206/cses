#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>nums(n);
    int idx = 1;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums[i] = {num,idx};
        idx++;

    }
    sort(nums.begin(),nums.end());

    int i = 0 , j = n-1;
    while(i<j){
        if(nums[i].first+nums[j].first == x){
            cout<<nums[i].second<<" "<<nums[j].second;
            return 0;
        }
        else if(nums[i].first+nums[j].first < x) i++;
        else j--;
    }
    cout<<"IMPOSSIBLE";

    return 0;
}