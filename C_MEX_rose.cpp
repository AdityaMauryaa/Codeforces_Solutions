#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)
const int MOD = 1000000007;
const long long INF = 1000000000000000000LL;

long long gcdll(long long a, long long b) { return b ? gcdll(b, a % b) : a; }
long long lcmll(long long a, long long b) { return a / gcdll(a, b) * b; }
long long modpow(long long a, long long e, long long m = MOD) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % m;
        a = a * a % m;
        e >>= 1;
    }
    return r;
}

void solve() {
    int n,k;
    cin>>n>>k;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mpp[x]++;
    }
    int req=0;
    for(int i=0;i<k;i++){
        if(mpp.count(i)==0)req++;
    }
    cout<<max(req,mpp[k])<<endl;
}

int main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}