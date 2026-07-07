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
    long long x,y;
    cin>>x>>y;
    if(x<y){
        if(y%2){
            cout<<(y*y-x+1);
        }else{
            cout<<((y-1)*(y-1)+x);
        }
    }else {
        if(x%2==0){
            cout<<(x*x-y+1);
        }else{
            cout<<((x-1)*(x-1)+y);
        }
    }
    /*
    Logic:
         1  2  3  4

    0    1  2  9 10 25
    1    4  3  8 11 24
    2    5  6  7 12 23
    3   16 15 14 13 22
    4   17 18 19 20 21
    x,y
    2,3
    5->9
    
    */
   cout<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}