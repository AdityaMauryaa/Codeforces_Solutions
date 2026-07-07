#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
           ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto num:ans)cout<<num<<" ";
    cout<<endl;
}

/*
9->1001

*/
int main() {
    FAST_IO;
    // freopen("00_input.txt", "r", stdin);
    auto start = high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while (t--) solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}