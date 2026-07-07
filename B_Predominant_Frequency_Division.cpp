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
    bool left=false;
    bool mid=false;
    vector<int>arr(n);
    vector<int>pref(n);
    int x=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1)x++;
        else x--;
        pref[i]=x;
    }
    x=0;
    for(int i=n-2;i>=1;i--){
        if(arr[i]==3)x--;
        else x++;
        if(x>=0 && pref[i-1]>=0){
            left=true;
            mid=true;
            break;
        }
        if(x<0)x=0;
    }
    if(left && mid)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

/*
first: {1s>=2s+3s}
second: {1s+2s>=3s}
third: {non-empty}

ex=1 3 3 2
one=1
two=1
three=2;
{1}->1s>=2s+3s
{2}->1s+2s>=3s
{3,3}

   1 3 3 1 2 3
1  2 2 2 3 3 3
2  1 1 1 1 2 1
3  0 1 2 2 2 3

       1 1 1 2 3 3
       0 1 2 2 2 3   

*/

int main() {
    int t = 1;
    pre();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}