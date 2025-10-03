#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid;
vector<int> state; // 0 is for entering , 1 is for inside stack and 2 is for exiting
vector<int> parent;
vector<int> cycle;
bool dfs(int node){
    state[node] = 1;
    for(auto it : grid[node]){
        if(state[it]==0){
            parent[it] = node;
            if(dfs(it)) return true;
        }

        else if(state[it]==1 && it != parent[node]){
            cycle.clear();
            cycle.push_back(it);
            int cur = node;
            while(cur != it){
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(it);
            reverse(cycle.begin(), cycle.end()); 
            return true;
        }
    }
    state[node]=2;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.resize(n + 1);
    parent.assign(n+1,-1);
    state.assign(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(state[i]==0){
            parent[i] = -1;
            if(dfs(i)){
                cout<<cycle.size()<<endl;
                for(auto it : cycle){
                    cout<<it<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}