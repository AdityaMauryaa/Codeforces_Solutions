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
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    int ans=0;
    int sum=0;
    int started=0;
    priority_queue<int> pq;
    for(int i=0;i<n;){
        if(started){
            if(a[i]<0){
               while(i<n && a[i]<0){
                   pq.push(a[i]);
                   i++;
               }
               while(!pq.empty() && sum+pq.top()>=0){
                sum+=pq.top();
                pq.pop();
                ans++;
               }
               while(!pq.empty())pq.pop();
            }else{
                sum+=a[i];
                ans++;
                i++;
            }
            
        }else if(a[i]>=0){
            started=1;
            sum+=a[i];
            ans++;
            i++;
        }else i++;
        
    }
    cout<<ans<<"\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}