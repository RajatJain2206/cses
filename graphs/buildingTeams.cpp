#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>grid;

vector<int>colors; // adjacent nodes should have opposite color
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.resize(n+1);
    colors.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(colors[i]==-1){
            queue<int>q;
            q.push(i);
            colors[i] = 0;

            while(!q.empty()){
                int top = q.front();
                q.pop();

                for(auto it : grid[top]){
                    if(colors[it]==-1){
                        colors[it] = 1-colors[top];
                        q.push(it);
                    }

                    else if(colors[it]==colors[top]){
                        cout<<"IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<colors[i]+1<<" ";
    }
    
    

    return 0;
}