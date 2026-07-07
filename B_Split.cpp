#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<thread>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;

void pre(){
    freopen("00_input.txt", "r", stdin);
    // freopen("00_output.txt", "w", stdout);
};
template<typename T>
T mx(T a, T b, T c) {
    return max(a, max(b, c));
}
template<typename T>
T mn(T a, T b, T c) {
    return min(a, min(b, c));
}
void solve(){
    int n;
    cin>>n;
    vector<int>arr(2*n);
    unordered_map<int,int>mpp;
    int odd=0,even=0;
    for(auto &num:arr){
        cin>>num;
        mpp[num]++;
    }
    for(auto [key,value]:mpp){
            if(value%2)odd++;
            else even++;
    }
    even=min(even,n);
    if(!odd){
        if((even%2)!=(n%2))even--;
        even=max(even,0);
    }
    cout<<odd+2*even<<endl;
};

int main() {
    // pre();
    // auto start = high_resolution_clock::now();
    int t=1; 
    cin>>t;
    while(t--)
        solve();
    // auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}


