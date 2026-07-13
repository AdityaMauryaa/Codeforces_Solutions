#include<bits/stdc++.h>   
using namespace std;

void pre(){
#ifndef ONLINE_JUDGE
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
#endif
}
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2)cout<<i+1<<" ";
        else cout<<i-1<<" ";
    }
    cout<<endl;

}

int main() {
    int t = 1;
    pre();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}