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
    
};
void solve(){
    int a,b;
    cin>>a>>b;
    if(int(log2(a))<int(log2(b))){
        cout<<-1<<endl;
    return ;}
    if(a==b){
        cout<<0<<endl;
    return ;
    }
    vector<int>nums;
    int count=0;
    int temp=a;

    while(a!=b && count<100){
        int c=0;
        for(int i=0;i<32;i++){
            int last=c;
            if(((b>>i)&1)!=((a>>i)&1)){
                c^=(1<<i);
            }
            if(c>a){
                c=last;
                break;
            }
            
        }
        a^=c;
        nums.push_back(c);
        count++;
    }
    cout<<count<<endl;
    for(auto num:nums){
        cout<<num<<" ";
    } 
    cout<<endl;
};
/*
((..((9^a)^b)^c...)^z=6
1 1 1 0
1 0 0 0
     
*/

int main() {
    // pre();
    auto start = high_resolution_clock::now();
    int t = 1;
    cin >> t;
    while (t--) solve();
    auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}