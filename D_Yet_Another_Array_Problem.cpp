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
void make_primes(){
    int arr[501]={0};
    for(int i=2;i<501;i++){
        if(arr[i])continue;
        primes.push_back(i);
        for(int j=i*i;j<501;j+=i){
            arr[j]=1;
        }
    }
}
void solve(){
    make_primes();
    int  n;
    cin>>n;
    vector<long long>arr(n);
    for(auto &num:arr)cin>>num;
    for(auto num:primes){
        for(auto x:arr){
            if(gcd(x,num)==1){
                cout<<num<<endl;
                return ;
            }
        }
    }
    cout<<endl;
};

/*
4 9 6 8 2 6 7 8 2
2 4 6 6 7 8 8 9 

*/

int main() {
    pre();
    auto start = high_resolution_clock::now();
    int t;
    cin>>t;
    while(t--)
        solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}


