#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
void pre()
{   
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), discount(k);
    for (int &a:arr) cin >> a;
    for (int &d:discount)cin>>d;
    sort(arr.rbegin(),arr.rend());      
    sort(discount.begin(),discount.end()); 
    long long ans=0;
    int i=0,j=0;
    while(j<k && i<n) {
        int cost=discount[j];
        if(cost==1){
            i++;
        }else{
            int limit = i + cost;
            while(i<min(n,limit-1)){
                ans+=1LL*arr[i];
                i++;
            }
            i++;
        }
        j++;
    }
    while (i<n){
        ans+=1LL*arr[i++];
    }
    cout << ans << "\n";
}
int main() {
    // pre();
    int t=1;
    cin>>t;
    while(t--)solve();
    
    return 0;
}