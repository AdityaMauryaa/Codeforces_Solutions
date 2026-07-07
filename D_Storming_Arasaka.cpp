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
int primes[1000001]={0};
void seive(){
     for (int i = 2; i <= 1000001; i++)
        primes[i] = i;
    for(int i=2;i*i<=1000000;i++){
        if(primes[i]==i){
            primes[i]=i;
            for(int j=i*i;j<=1000000;j+=i){
                 if (primes[j] == j)
                    primes[j] = i;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int cnt=0;
    int ans=0,sum=0;
    while(n > 1){
    int p = primes[n];
        while(n % p == 0){
            n /= p;
            cnt++;
        }
        ans=max(ans,cnt);
        sum++;
    }
    cout<<ans+sum-1<<endl;

}

int main() {
    int t = 1;
    pre();
    cin >> t;
    seive();
    while (t--) {
        solve();
    }
    return 0;
}
/*
120= 2^3*3^1*5^1

2^1*3^1,2^1*5^1
2^1*3^1*5^1, 2^2*5^1 , 2^2*3^1 , 2^3 , 2^2*5^1 , 
2^2*3^1*5^1,2^3*3^1,2^3*5^1
2^3*3^1*5^1

layer1=
x=prime[i],count=0
while(i>1 && prime[i]<=i){
        n/=prime[i];//1
        if(i>1 && prime[i]!=x){
            ans.push_back({x,count});
            x=prime[i];
        }
    }
    layer1=







11
3
3*11














































*/