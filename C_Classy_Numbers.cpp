#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[19][2][4];

ll calc(const string &s, int idx, int tight, int n, int count) {
    if (idx == n)
        return 1;  // valid number formed
    ll &res = dp[idx][tight][count];
    if (res != -1)
        return res;
    res = 0;
    int r = tight ? (s[idx] - '0') : 9;

    for (int i = 0; i <= r; i++) {
        int ntight = tight && (i == r);
        int ncount = count + (i != 0);
        if (ncount <= 3)
            res += calc(s, idx + 1, ntight, n, ncount);
    }
    return res;
}

ll finalSolve(ll n) {
    if (n < 0)
        return 0;
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return calc(s, 0, 1, s.size(), 0);
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << finalSolve(r) - finalSolve(l - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
