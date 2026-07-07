#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<thread>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

void pre(){
    freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
};
template<typename T>
T mx(T a, T b, T c) {
    return max(a, max(b, c));
}
template<typename T>
T mn(T a, T b, T c) {
    return min(a, min(b, c));
}
void solve(){
    int n,y,r;
    cin>>n>>y>>r;
    int rp=r;
    int yp=floor(y/2);
    cout<<r+min(n-r,yp)<<endl;
};

int main() {
    // pre();
    auto start = high_resolution_clock::now();
    int t=1; 
    cin>>t;
    while(t--)
        solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}


