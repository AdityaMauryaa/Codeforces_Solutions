#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
void pre()
{   
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (n <= 2) {            
        cout << "YES\n";
        return;
    }
    int i = 1;
    while (i < n && a[i] > a[i-1]) i++;   
    while (i < n && a[i] < a[i-1]) i++;  

    if (i == n) cout << "YES\n";
    else        cout << "NO\n";
}
int main() {
    // pre();
    int t=1;
    cin>>t;
    while(t--)solve();
    
    return 0;
}