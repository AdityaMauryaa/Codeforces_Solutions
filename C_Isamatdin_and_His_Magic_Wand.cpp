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

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &num:arr){
        cin>>num;
    }
    int odd=0,even=0;
    for(auto num:arr){
        if(num&1)odd++;
        else even++;
    }
    if(even && odd)sort(arr.begin(),arr.end());
    for(auto &num:arr){
        cout<<num<<" ";
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


