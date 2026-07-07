#include <iostream>      
#include <vector>        
#include <algorithm>     
#include <string>        
#include <map>           
#include <unordered_map> 
#include <set>           
#include <unordered_set> 
#include <queue>         
#include <stack>         
#include <cmath>         
#include <climits>       

using namespace std;

void pre(){
#ifndef ONLINE_JUDGE
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
#endif
}

void solve() {
    int n;
    cin >> n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=1ll*(1ll*(n/i)*(n/i));
    }
    cout << ans << endl;
}
/*
a,b,c
gcd(gcd(a,b)/a*b,gcd(b,c)/b*c)=gcd(a,c) //requirements
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

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