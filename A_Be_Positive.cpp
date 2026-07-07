#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

void pre(){
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
};
void solve(){
    int n;
    cin>>n;
    int neg=0,zero=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0)zero++;
        else if(x<0)neg++;
    }
    cout<<(zero+(neg%2)*2)<<endl;
};
int main() {
// pre();
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}