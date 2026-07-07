#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <numeric>
#include <chrono>
using namespace std;
using namespace std::chrono;

void pre(){
    // freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
};
int mx(int a,int b,int c){
    return max(a,max(b,c));
}
int mn(int a,int b,int c){
    return min(a,min(b,c));
}
long long calc(const vector<long long>& sub) {
    int m = sub.size();
    if (m <= 1) return 0;
    vector<int>parent(m, -1);
    stack<int> st;
    for (int i = 0; i < m; i++) {
        int last = -1;
        while (!st.empty() && sub[st.top()] <= sub[i]) {
            last = st.top();
            st.pop();
        }
        if (last != -1) parent[last] = i;
        if (!st.empty()) parent[i] = st.top();
        st.push(i);
    }
    long long sum = 0;
    for (int i = 0; i < m; i++)
        if (parent[i] != -1)
            sum += sub[parent[i]];
    return sum;
}
void solve(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &nm : a) cin >> nm;
    long long M = *max_element(a.begin(), a.end());
    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] == M)
            pos.push_back(i);
    int r = pos.size();
    long long segSum = 0;
    int s = 0;
    for (int j = 0; j < r; j++) {
        int start = (pos[j] + 1) % n;
        int end = pos[(j + 1) % r];
        vector<long long> sub;
        int cur = start;
        while (cur != end) {
            sub.push_back(a[cur]);
            cur = (cur + 1) % n;
        }
        if (!sub.empty()) {
            s++;
            segSum += calc(sub);
        }
    }
    long long ans = segSum + (s + r - 1LL) * M;
    cout << ans << "\n";
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
