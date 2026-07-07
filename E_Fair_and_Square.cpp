#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;
long long ans = 0;

void pre() {
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
}



void count_nodes(int node, int parent, vector<vector<int>>& adj,
                 vector<int>& nodes_count) {
    nodes_count[node] = 1;

    for (int child : adj[node]) {
        if (child == parent) continue;

        count_nodes(child, node, adj, nodes_count);
        nodes_count[node] += nodes_count[child];
    }
}

void dfs(int node, int parent, vector<vector<int>>& adj,
         vector<int>& nodes_count, int prev_count, vector<int>& a) {
        long long rt = sqrt(a[node]);    
        if(rt * rt == a[node]) {
         long long sum = 0;
    long long sqr_sum= 0;
    for(auto x:adj[node]){
        if(x==parent){
            sum+=prev_count;
            sqr_sum+=1LL*prev_count*prev_count;
        }else{
            sum+=nodes_count[x];
            sqr_sum+=1LL*nodes_count[x]*nodes_count[x];
        }
    }
    ans+=1ll*(sum*sum-sqr_sum)/2;
    long long pref1 = 0;
    long long pref2 = 0;
    //2 3 4 5 6 7 8 9
    for (long long x : adj[node]) {
        if(x==parent){
            ans+=pref2*prev_count;
            pref2+=pref1*prev_count;
            pref1+=prev_count;
        }else{
            ans+=pref2*nodes_count[x];
            pref2+=pref1*nodes_count[x];
            pref1+=nodes_count[x];
        }
    }
    
    }
    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child,node,adj,nodes_count,prev_count+
            nodes_count[node] - nodes_count[child],a);
    }
}
void solve() {
    ans = 0;

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    vector<int> nodes_count(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    count_nodes(1, 0, adj, nodes_count);
    dfs(1, 0, adj, nodes_count, 0, a);

    cout << ans << '\n';
}
int main() {
    // pre();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}