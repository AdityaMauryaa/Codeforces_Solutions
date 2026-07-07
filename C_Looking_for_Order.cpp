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
struct Point{
    Point() : x(0), y(0) {} 
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
    int x,y;
};
int vis[26]={0};
int dis[26][26]={0};
int dist=1000000000.00;
vector<int>order;
vector<int>temp;

void dfs(int idx,int count,int taken,int n,int ds){
    vis[idx]=1;
    if(count==n){
        if(ds+dis[idx][0]<dist){
            dist=ds+dis[idx][0];
            order=temp;
        }else if(ds+dis[idx][0]==dist){
            if(order.size()>temp.size())order=temp;
        }
        vis[idx]=0;
        return ;
    }

    if(taken){
            temp.push_back(0);
            dfs(0,count,0,n,dis[idx][0]+ds);
            temp.pop_back();
        }
        if(taken==2){vis[idx]=0;return;}
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(taken<2){
            temp.push_back(i);
            dfs(i,count+1,taken+1,n,ds+dis[idx][i]);
            temp.pop_back();
        }
    }
    vis[idx]=0;
}
void solve(){
    Point o;
    cin>>o.x>>o.y;
    int n;
    cin>>n;
    vector<Point>coordinates;
    coordinates.push_back(o);
    for (int i = 1; i <=n; i++) {
        int x,y;
        cin>>x>>y;
        coordinates.push_back(Point(x,y));
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            auto nxt=coordinates[j];
            auto curr=coordinates[i];
            int dx=curr.x-nxt.x;
            int dy=curr.y-nxt.y;
            int ds=dx*dx+dy*dy;
            dis[i][j]=ds;
            dis[j][i]=ds;
        }
    }
    temp.push_back(0);
    dfs(0,0,0,n,0);
    cout<<dist<<endl;
    for(int i=0;i<order.size();i++){
        cout<<order[i]<<" ";
    }
    cout<<0<<endl;

};
int main() {
    // pre();
    // auto o = high_resolution_clock::now();
    int t=1; 
    // cin>>t;
    while(t--)
        solve();
    // auto end = high_resolution_clock::now();
    // cout << "Time: " << duration_cast<milliseconds>(end - o).count() << " ms\n";
    return 0;
}



