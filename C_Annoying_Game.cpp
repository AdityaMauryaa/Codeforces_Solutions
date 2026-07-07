#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;
void pre(){
    freopen("00_input.txt", "r", stdin);
};
template<typename T>
T mx(T a, T b, T c) {
    return max(a, max(b, c));
}
template<typename T>
T mn(T a, T b, T c) {
    return min(a, min(b, c));
}

using ll = long long;
const ll INF = (ll)4e18;

vector<ll> stmn, stmx;  
int STN;

void seg_init(int n) {
    STN = n;
    stmn.assign(4 * n, INF);
    stmx.assign(4 * n, -INF);
}

void segmentTreeBuildMin(int idx, int l, int r, const vector<ll> &a) {
    if (l == r) {
        stmn[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    segmentTreeBuildMin(idx << 1, l, mid, a);
    segmentTreeBuildMin(idx << 1 | 1, mid + 1, r, a);
    stmn[idx] = min(stmn[idx << 1], stmn[idx << 1 | 1]);
}

void segmentTreeBuildMax(int idx, int l, int r, const vector<ll> &a) {
    if (l == r) {
        stmx[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    segmentTreeBuildMax(idx << 1, l, mid, a);
    segmentTreeBuildMax(idx << 1 | 1, mid + 1, r, a);
    stmx[idx] = max(stmx[idx << 1], stmx[idx << 1 | 1]);
}

void seg_build(const vector<ll>& a) {
    segmentTreeBuildMin(1, 0, STN - 1, a);
    segmentTreeBuildMax(1, 0, STN - 1, a);
}

ll query_min(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return stmn[idx];
    int mid = (l + r) >> 1;
    return min(query_min(idx << 1, l, mid, ql, qr),
               query_min(idx << 1 | 1, mid + 1, r, ql, qr));
}

ll query_max(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return -INF;
    if (ql <= l && r <= qr) return stmx[idx];
    int mid = (l + r) >> 1;
    return max(query_max(idx << 1, l, mid, ql, qr),
               query_max(idx << 1 | 1, mid + 1, r, ql, qr));
}

ll seg_query_min(int l, int r) {
    if (l > r) return INF;
    return query_min(1, 0, STN - 1, l, r);
}

ll seg_query_max(int l, int r) {
    if (l > r) return -INF;
    return query_max(1, 0, STN - 1, l, r);
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll>a(n),b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    if (k % 2 == 0) {
        ll maxi = -INF, curr = -INF;
        for (int i = 0; i < n; i++) {
            curr = (curr < 0 ? a[i] : curr + a[i]);
            maxi = max(maxi, curr);
        }
        cout << maxi << "\n";
        return;
    }
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    vector<int> left(n), right(n);

    {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && b[st.back()] <= b[i])
                st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
    }
    {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && b[i] >= b[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        while (!st.empty()) {
            right[st.back()] = n;
            st.pop_back();
        }
    }
    seg_init(n + 1);
    seg_build(pref);
    ll ans = -INF;
    for (int j = 0; j < n; j++) {
        int Lb = left[j];
        int Rb = right[j] - 1;
        ll minLeft = seg_query_min(Lb + 1, j);
        ll maxRight = seg_query_max(j + 1, Rb + 1);
        ll val = b[j] + maxRight - minLeft;
        ans = max(ans, val);
    }
    cout << ans << endl;
}

int main() {
    // pre();
    // auto start = high_resolution_clock::now();
    int t=1; 
    cin>>t;
    while(t--)
        solve();
    // auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}
