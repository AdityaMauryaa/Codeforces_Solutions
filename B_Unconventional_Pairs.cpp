#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

#define any(x) (x).begin(), (x).end()
void pre(){
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
};
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int ans=0;
    for(auto &num:arr){
        cin>>num;
    }
    sort(any(arr));
    for(int i=0;i<=n-2;i+=2){
        ans=max(ans,abs(arr[i]-arr[i+1]));
    }
    cout<<ans<<endl;
};
int main() {
// pre();
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}