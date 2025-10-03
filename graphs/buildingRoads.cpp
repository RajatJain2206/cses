#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>grid;
vector<int>visited;
void dfs(int node , vector<int>&temp){
    visited[node] = 1;
    temp.push_back(node+1);
    for(auto edge : grid[node]){
        if(!visited[edge]){
            dfs(edge,temp);
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n);
    int x1,x2;
    for(int i=0;i<m;i++){
        cin>>x1>>x2;
        grid[x1-1].push_back(x2-1);
        grid[x2-1].push_back(x1-1);
    }
    visited.assign(n,0);

    vector<vector<int>>result;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>temp;
            dfs(i,temp);
            result.push_back(temp);
        }
    }

    cout<<(int)result.size()-1<<endl;
    for(int i=0;i<(int)result.size()-1;i++){
        int backEle = result[i].size()-1;
        cout<<result[i][backEle]<<" "<<result[i+1][0]<<endl;
    }
    
    return 0;
}