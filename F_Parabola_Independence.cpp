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
using namespace std;

void pre(){
 freopen("00_input.txt", "r", stdin);
 freopen("00_output.txt", "w", stdout);
}

class QuadraticFunction {
public:
    double a, b, c; 
    QuadraticFunction(double a, double b, double c):a(a), b(b), c(c) {}
    double evaluate(double x){
        return a * x * x + b * x + c;
    }
    double vertexX(){
        return -b / (2 * a);
    }
    double vertexY() {
        double x = vertexX();
        return evaluate(x);
    }
    QuadraticFunction operator-(const QuadraticFunction& other) {
        return QuadraticFunction(a - other.a, b - other.b, c - other.c);
    }
    bool isIndependent() {
        double discriminant=b * b - 4 * a * c;
        return discriminant<0.0;
    }
};


void solve() {
    int n;
    cin>>n;
    vector<QuadraticFunction> functions(n);
    vector<vector<int>> adj1(n), adj2(n);
    vector<int> ind1(n,0),ind2(n,0);
    for(int i=0;i<n;i++){
        double a,b,c;
        cin>>a>>b>>c;
        functions[i]=QuadraticFunction(a,b,c);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            QuadraticFunction diff=functions[i]-functions[j];
            if(diff.isIndependent()){
                adj1[i].push_back(j);
                adj2[j].push_back(i);
                ind1[i]++;
                ind2[j]++;
            }
        }
    }


}

/*
Now my question is converted into picking the cherries which are indepentdnt in nature
f1={c1,c2,c3,c4,c5}
*/

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}