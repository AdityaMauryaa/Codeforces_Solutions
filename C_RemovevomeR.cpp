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
    string s;
    cin>>s;
    int ans=1;
    vector<int> v;
    v.push_back(s[0]-'0');
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans++; 
            v.push_back(s[i]-'0');
        }
    }
   if(ans==2)cout<<2<<endl;
   else cout<<1<<endl;
}

int main() {
    int t = 1;
    // pre();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}