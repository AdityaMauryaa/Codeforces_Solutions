#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>vis(n+1,1);
    vector<int>indegree(n+1,0);
    vector<vector<int>>adj(n+1);
    queue<int>q;
    for(int i=1;i<n;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x>=y){
            adj[u].push_back(v);
            indegree[v]++;
        }
        else {indegree[u]++;
            adj[v].push_back(u);
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            vis[i]=0;
        }
    }
    int value=n;
    vector<int>ans(n+1,-1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(ans[u]==-1){
            ans[u]=value--;
        }
        for(auto &v:adj[u]){
            if(u!=v && indegree[v]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    // freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}