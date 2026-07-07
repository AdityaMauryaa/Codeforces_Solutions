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
    if(n==1)cout<<1;\
    else if(n<=3)cout<<"NO SOLUTION";
    else if(n==4)cout<<2<<" "<<4<<" "<<1<<" "<<3;
    else if(n%2==1){
        for(int i=n-1;i>=1;i-=2)cout<<i<<" ";
        for(int i=n;i>=1;i-=2)cout<<i<<" ";
    }
    else{
        for(int i=n;i>=1;i-=2)cout<<i<<" ";
        for(int i=n-1;i>=1;i-=2)cout<<i<<" ";
    }
}
/*
n=5

*/
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}