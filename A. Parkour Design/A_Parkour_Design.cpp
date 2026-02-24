// #include<bits/stdc++.h>
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
    int x,y;
    cin>>x>>y;
    if(((-1)*x<=4*y && 4*y<=2*x) && (x+y)%3==0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
   
}

int main() {
    int t = 1;
//  pre(); // For multiple test cases, uncomment the line below and comment out the line above
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}