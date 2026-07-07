#include <iostream>      // basic I/O (cin, cout)
#include <vector>        // dynamic arrays
#include <algorithm>     // sort, max, min, binary_search
#include <string>        // string handling
#include <map>           // ordered maps (key-value pairs)
#include <unordered_map> // fast hash maps
#include <set>           // ordered sets
#include <unordered_set> // fast hash sets
#include <queue>         // queue, priority_queue (heaps)
#include <stack>         // stack data structure
#include <cmath>         // math functions (sqrt, abs, pow)
#include <climits>       // INT_MAX, INT_MIN, LLONG_MAX, etc.

using namespace std;

void pre(){
#ifndef ONLINE_JUDGE
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
#endif
}

int solveDepth(vector<vector<int>>&a,int node,long long &ans){
    int count=0;
    int m=0,s=0;
    for(auto x:a[node]){
        count=solveDepth(a,x,ans);
        if(count>m){
            s=m;
            m=count;
        }else if(count>s){
            s=count;
        }
    }
    ans+=1ll*(s+1);
    return m+1;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>>a(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        a[x].push_back(i);
    }
   long long ans=0;
    solveDepth(a,1,ans);
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    pre();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}