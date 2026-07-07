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
    // freopen("00_output.txt", "w", stdout);
};
int mx(int a,int b,int c){
    return max(a,max(b,c));
}
int mn(int a,int b,int c){
    return min(a,min(b,c));
}
void solve(){
    int a,b,c,n,ans=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[n-1])ans++;
    }
    cout<<ans<<endl;
    return ;
    // vector<int>arr(n);
    // for(auto &num:arr)cin>>num;
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


