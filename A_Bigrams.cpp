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
    int k;
    cin>>k;
    vector<int>a(k,0);
    int count=0;
    for(auto &num:a)cin>>num;
    for(auto num:a){
        if(num>=3){
            cout<<"YES"<<endl;
            return;
        }else{
            count+=int(num/2);  
        }
        if(count>=2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    int t = 1;
    pre();
    cin >> t;
    for(int i=0;i<t;i++){
        // cout<<"testcase : "<<i+1<<" ";
        solve();
    }
    return 0;
}