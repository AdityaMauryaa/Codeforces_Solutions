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


bool valid(int x, int y, int z) {
    for (int k = 0; k < 31; ++k) {
        int X = (x >> k) & 1;
        int Y = (y >> k) & 1;
        int Z = (z >> k) & 1;
        if (!(
            (X == 0 && Y == 0 && Z == 0) ||
            (X == 1 && Y == 0 && Z == 0) ||
            (X == 0 && Y == 1 && Z == 0) ||
            (X == 0 && Y == 0 && Z == 1) ||
            (X == 1 && Y == 1 && Z == 1)
        )) return false;
    }
    return true;
}
void solve() {
    int arr[3]={0,0,0};
    cin>>arr[0]>>arr[1]>>arr[2];
    if(valid(arr[0],arr[1],arr[2]))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

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
/*
3- 011
2- 001
6- 101
*/