#include <iostream>      // basic I/O (cin, cout)
#include <vector>        // dynamic arrays
#include <algorithm>     // sort, max, min, binary_search
#include <string>        // string handling
#include <map>           // ordered maps (key-value pairs)
#include <unordered_map> // fast hash maps
#include <set>           // ordered sets
#include <unordered_set> // fast hash sets
#include <queue>         // queue, priority_queue (heaps)
#include <stack>         // stack data structure
#include <cmath>         // math functions (sqrt, abs, pow)
#include <climits>       // INT_MAX, INT_MIN, LLONG_MAX, etc.
#include<shared_mutex>
using namespace std;
template<typename T>
class Stack{
    int sz=0;//size
    struct Node{
        T value;
        Node* prev;
        ~Node(){
            cout<<"Node Deleted From Heap Memory"<<endl;
        }
    };
    std::shared_mutex m;
    Node* curr=NULL;
    public:
    void push(T element){
        if(sz==100000)throw "Stack Overflow";
        unique_lock<shared_mutex>lg(m);
        Node * newElement =new Node;
        (*newElement).value=element;
        (*newElement).prev=curr;
        curr=newElement;
        sz++;
    }
    void pop(){
        if(sz==0)throw "Trying to remove element from empty stack ";
        unique_lock<shared_mutex>lg(m);
        Node* temp=curr;
        curr=(*curr).prev;
        delete temp;
        temp=NULL;
        sz--;
    }
    T top(){
        shared_lock<shared_mutex>lg(m);
        if(sz==0){
            throw "Trying to access empty stack element";
        }
        return (*curr).value;
    }
    int getSize(){
        shared_lock<shared_mutex>lg(m);
        return sz;
    }
    ~Stack() {
    while(curr!=NULL) {
        Node* temp = curr;
        curr=curr->prev;
        delete temp;
    }
}


};
void solve() {
    Stack<int>st;
    st.push(45);
    st.push(50);
    st.push(10);
    st.push(20);
    st.push(0);
    st.push(10);
    while(st.getSize()>0){
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}