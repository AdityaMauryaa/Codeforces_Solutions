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
void solve() {
    int n;
    cin>>n;
    int one=0;
    int two=0;
    int three=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1)one++;
        else if(x==2)two++;
        else three++;
    }

}

/*
[1,1,2,3],[1,2,3],[3];
1>=3

1 2 3
[1][]
*/

int main() {
    int t = 1;
    pre();
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}