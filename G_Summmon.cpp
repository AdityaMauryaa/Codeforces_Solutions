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
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
}
void solve() {
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    long long sm=0;
    for(int i=0;i<n;i++){
        sm+=1ll*(a[i]-b[i]);
        if(sm>0){
            cout<<"NO"<<endl;
            break;
        }`
    }
    cout<<"YES"<<endl;
}

int main() {
    int t = 1;
    pre();
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}