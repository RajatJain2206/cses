#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>x(n);
    for(auto &x : x){
        cin>>x;
    }

    set<int>s;
    for(auto &x : x){
        s.insert(x);
    }

    cout<<s.size()<<endl;
    return 0;
}