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
    int n,c;
    cin>>n>>c;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
        if(a[i]<b[i]){
            ans=-1;
            break;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int temp=c;
    for(int i=0;i<n;i++){
        if(a[i]<b[i]){
            temp=-1;
            break;
        }else temp+=a[i]-b[i];
    }
    if(temp==-1 and ans==-1)ans=-1;
    else if(temp!=-1 and ans==-1)ans=temp;
    else if(temp==-1 and ans!=-1)ans=ans;
    else ans=min(ans,temp);
    cout<<ans<<endl;
    /*
2 4 5 3 6 8
5 8 3 1 2 5

2 3 4 5 6 8
1 2 3 5 5 8

ans=c+1+1+1+1

    */
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