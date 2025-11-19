#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isPossible(vector<int>&freq, int c){
    int total = 0;
    int maxi = 0;

    for(int i=0;i<26;i++){
        if(freq[i]>freq[maxi]) maxi = i;
        total+=freq[i];
    }

    return (freq[maxi]<=(total+1)/2) && (freq[c]<=total/2);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n = s.size();
    vector<int>freq(26,0);
    for(char ch : s) freq[ch-'A']++;

    vector<char>ans(n);
    int last = -1;
    for(int i=0;i<n;i++){
        bool placed = false;
        for(int c=0;c<26 && !placed;c++){
            if(freq[c]==0 || c == last) continue;
            freq[c]--;

            if(isPossible(freq,c)){
                ans[i] = char(c+'A');
                last = c;
                placed = true;
            }
            else{
                freq[c]++;
            }
        }
        if(!placed){
            cout<<-1<<"\n";
            return 0;
        }
    }
    for(char ch : ans) cout<<ch;
    cout<<"\n";
    return 0;
}