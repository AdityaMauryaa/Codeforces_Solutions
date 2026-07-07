#include <iostream>
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
    freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
};
vector<int>primes;
void make_primes(int n){
    vector<int>arr(n+1);
    iota(arr.begin(),arr.end(),0);
    for(int i=2;i<=n;i++){
        if(arr[i]!=i)continue;
        primes.push_back(i);
        for(int j=i*i;j<=n;j+=i){
            arr[j]=i;
        }
    }
}
void solve(){
    int  n,k,x;
    cin>>n>>k>>x;
    vector<int>arr(n);
    for(auto &num:arr)cin>>num;


};
/*
4
0 1 2
0 1 2 3 4 5 6 7 8 


n 5 100
1 10 20 30 40 10
0 1 2 4

*/
int main() {
    // make_primes(100000);
    // pre();
    auto start = high_resolution_clock::now();
    int t;
    cin>>t;
    while(t--)
        solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " <<duration_cast<milliseconds>(end - start).count()<< " ms\n";
    return 0;
}


