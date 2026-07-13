#include <bits/stdc++.h>      
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
    if(n==1){
        cout<<1;
    }else if(n==2){
        cout<<-1;
    }
    else if(n==3){
        cout<<1<<" "<<2<<" "<<3;
    }else{
        cout<<1<<" "<<2<<" "<<6<<" "<<9;
        n-=4;
        long long num=18;
        while(n--){
            cout<<" "<<num;
            num*=2ll;
        }
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