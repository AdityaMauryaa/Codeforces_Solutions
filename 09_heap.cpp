#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;
template<typename T>class Min_Heap{
T arr[300100];
int n=0;
public:
    void Heapify(int n){
        int parent=n/2;
        if(parent>=1){
            if(arr[parent]>arr[n]){
                swap(arr[parent],arr[n]);
            }
            Heapify(parent);
        }
        return ;
    }
    void heapifyDown(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    if (left <= n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right <= n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyDown(smallest);
    }
    }
    int size(){
        return n;
    }
    void insert(T x){
        if(n==300099){
            throw runtime_error ("Heap overflow");
            return ;
        }
        n++;
        arr[n]=x;
        int parent=n/2;
        if(parent>=1){
            Heapify(n);
        }
        return ;
    }
    T top(){
        return arr[1];
    }
    void pop(){
        if (n == 0) throw runtime_error("Heap is empty");
        swap(arr[1], arr[n--]);
        if(n)
        heapifyDown(1);

    }
    void printheap(){
        cout<<"Heap Values ";
        for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
        Min_Heap(){};
    Min_Heap(vector<T>values){
        for(int i=0;i<values.size();i++){
        {
            insert(values[i]);
        }
    }
}
};
// 0 1 2 3 4 5 6 7 8
//-1 6 2

void start_function(){
    Min_Heap<int>arr({6,2,4,1,2,3,0});
    arr.printheap();
    cout<<arr.top()<<endl;
    arr.pop();
    cout<<arr.top()<<endl;
    arr.pop();
    cout<<arr.top()<<endl;
}
int main() {
    auto start = high_resolution_clock::now();
    start_function();
    auto end = high_resolution_clock::now();
    cout << "Time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
    return 0;
}