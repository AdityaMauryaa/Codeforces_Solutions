#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int dp[5][1000];
    int finalSolve(vector<vector<int>> dist,int mask,int i,int count){
        if(count==dist.size())return dist[i][0];
        if(dp[i][mask]!=-1)return dp[i][mask];
        for(int j=0;j<dist.size();j++){
            if(i==j || mask&(1<<j))continue;
            if(dp[i][mask]==-1)
            dp[i][mask]=dist[i][j]+finalSolve(dist,mask |(1<<j),j,count+1);
            else dp[i][mask]=min(dp[i][mask],dist[i][j]+finalSolve(dist,mask |(1<<j),j,count+1));
        }
        return dp[i][mask];
    }
    void solve(vector<vector<int>>&dist){
        memset(dp,-1,sizeof(dp));
        cout<<finalSolve(dist,0,0,0)<<endl;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    obj.solve(dist);
}
