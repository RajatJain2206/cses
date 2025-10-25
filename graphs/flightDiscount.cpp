#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD> > &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>flightPath(n);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        u--;
        v--;
        flightPath[u].push_back({v,wt});
    }

    vector<vector<int>>dist(n,vector<int>(2,1e18));
    dist[0][0] = 0; // 0 is undiscounted and 1 is discounted
    
    using tpl = tuple<int,int,int>;
    priority_queue<tpl,vector<tpl>,greater<tpl>>pq;
    pq.push({0,0,0});

    while(!pq.empty()){
        auto [d,u, used] = pq.top();
        pq.pop();

        if(d > dist[u][used]) continue;

        for(auto [v,w] : flightPath[u]){
            if(!used){
                if(d+w < dist[v][0]){
                    dist[v][0] = d+w;
                    pq.push({dist[v][0],v,0});
                }

                if(d+w/2<dist[v][1]){
                    dist[v][1] = d+w/2;
                    pq.push({dist[v][1],v,1});
                }
            }
            else{
                if(d+w<dist[v][1]){
                    dist[v][1] = d+w;
                    pq.push({dist[v][1],v,1});
                }
            }
        }
    }

    cout<<min(dist[n-1][0],dist[n-1][1])<<"\n";

    
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    solve();
    return 0;
}

    