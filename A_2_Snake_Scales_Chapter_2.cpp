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
bool check(vector<int>arr,int mid,int n){
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])>mid)return false;
    }
    return true;
}
void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);

    int ans=1e9+5;
    for(auto &num:arr){
        cin>>num;
        ans=min(ans,num);
    }
    vector<int> dp(n);
    for(int i=1;i<n;i++){
        ans=max(ans,min(arr[i]-arr[i-1],arr[i]));
    }
    cout<<ans<<endl;
}

int main() {
    FAST_IO;
    freopen("00_input.txt", "r", stdin);
    auto start = high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while (t--) solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}