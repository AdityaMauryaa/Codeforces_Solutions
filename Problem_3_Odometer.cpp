/*
Problem Statement:

Farmer John's cows are on a road trip!  The odometer on their car
displays an integer mileage value, starting at X (100 <= X <= 10^18)
miles at the beginning of their trip and ending at Y (X <= Y <= 10^18)
miles at the end of their trip.  Whenever the odometer displays an
'interesting' number (including at the start and end of the trip) the
cows will moo.  A number is 'interesting' if when you look at all its
digits except for leading zeros, at least half of these should be the
same.  For example, the numbers 3223 and 110 are interesting, while
the numbers 97791 and 123 are not.


*/
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

// void pre(){
//  freopen("00_input.txt", "r", stdin);
//  freopen("00_output.txt", "w", stdout);
// }

int dp[20][2][2][2]; // idx,tight,started,valid
long long calculate(string num,int idx,int tight,int started,vector<int>& freq){
    if(idx==num.size() && started){
        int total=0,maxi=0;
        for(int i=0;i<10;i++){
            total+=freq[i];
            maxi=max(maxi,freq[i]);
        }
        return maxi*2>=total?1:0;
    }o
    if(idx==num.size() && !started){
        return 0;
    }
    if(dp[idx][tight][started][0]!=-1){
        return dp[idx][tight][started][0];
    }
    long long ans=0;
    int limit=tight?num[idx]-'0':9;
    for(int i=0;i<=limit;i++){
        freq[i]++;
        if(started){
            ans+=calculate(num,idx+1,tight&(i==limit),1,freq);
        }else{
            ans+=calculate(num,idx+1,tight&(i==limit),i>0?1:0,freq);
        }
        freq[i]--;
    }
    return dp[idx][tight][started][0]=ans;
}
void solve() {
    int x,y;
    cin>>x>>y;
    memset(dp,-1,sizeof(dp));
    vector<int> freq(10,0);
    cout<<calculate(to_string(y),0,1,0,freq)-calculate(to_string(x-1),0,1,0,freq);
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}