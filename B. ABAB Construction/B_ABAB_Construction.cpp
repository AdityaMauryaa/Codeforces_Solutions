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
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
}
void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
 
  if (n % 2 != 0) {
    if (s[0] == 'b') {
      print("NO");
      return;
    }
    for (int i = 1; i < n; i += 2) {
      if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
        print("NO");
        return;
      }
    }
  } else {
    for (int i = 0; i < n; i += 2) {
      if (s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]) {
        print("NO");
        return;
      }
    }
  }
 
  print("YES");
}
int main() {
    // pre();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}