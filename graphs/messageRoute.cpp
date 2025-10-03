#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>grid;
vector<int>visited;
vector<int>parent;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n+1);
    visited.assign(n+1,0);
    parent.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    queue<int>q;
    q.push(1);
    visited[1]=1;
    
    while(!q.empty()){
        int topEle = q.front();
        q.pop();
        for(auto it:grid[topEle]){
            if(!visited[it]){
                q.push(it);
                visited[it]=1;
                parent[it] = topEle;
            }
        }
    }

    if(!visited[n]){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int>path;
        for(int i = n ; i!=1;i = parent[i]){
            path.push_back(i);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout<<path.size()<<"\n";
        for(auto it:path){
            cout<<it<<" ";
        }
    }
    
    return 0;
}