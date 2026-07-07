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
void solve(){
    int a,b,n;
    string s;
    cin>>a>>b>>n;
    int g = gcd(a, b);
    int wdw=a/g;
    int mini=(a+b-1)/b;
    if(mini>n){
        cout<<1<<endl;
    }
    else if(mini==n){
        if(mini%wdw){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }
    }else{
        if(wdw==1){
            cout<<1<<endl;
        }else{
             cout<<2<<endl;
        }
    }
            return ;
    // cin>>s;

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


