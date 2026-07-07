#include<iostream>
#include<vector>
using namespace std;
void sortArr(vector<int>&arr,int sz){
    int maximum=0;
    for(auto num:arr){
        maximum=max(num,maximum);
    }
    vector<int>dummy(maximum+1,0);
    for(auto num:arr){
        dummy[num]++;
    }
    for(int i=maximum;i>=0; i--){
        while(sz>=0 && dummy[i]>0){
            arr[sz--]=i;
            dummy[i]--;
        }
    }
}
int main(){
    int size=0;
    cin>>size;
    vector<int>arr(size);
    for(auto &num:arr)cin>>num;
    sortArr(arr,size-1);
    for(auto num:arr)cout<<num<<" ";
}