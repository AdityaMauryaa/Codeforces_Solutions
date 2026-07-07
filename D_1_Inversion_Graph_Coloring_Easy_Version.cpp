#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

void pre(){
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
};
void solve(){
    
};
int main() {
    pre();
    auto start = high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while (t--) solve();
    auto end = high_resolution_clock::now();
    cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}