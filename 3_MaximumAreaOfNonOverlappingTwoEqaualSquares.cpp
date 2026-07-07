#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
class Solution{
    public:
    int maximumAreaOfDisjointSquares(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0)),
                           suff(n,vector<int>(m,0));
        vector<int>hp(n,0),hs(n,0),vp(n,0),vs(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=n-i-1,y=m-j-1;
                if(grid[i][j]){
                    pref[i][j]=1;
                    if(i>=1 && j>=1){
                        pref[i][j]+=min(pref[i-1][j],min(pref[i-1][j-1],pref[i][j-1]));
                    }
                }
                if(grid[x][y]){
                    suff[x][y]=1;
                    if(x<n-1 && y<m-1){
                        suff[x][y]+=min(suff[x+1][y],min(suff[x+1][y+1],suff[x][y+1]));
                    }
                }
                hp[i]=max(pref[i][j],hp[i]);
                if(i)hp[i]=max(hp[i-1],hp[i]);
                vp[j]=max(pref[i][j],vp[j]);
                if(j)vp[j]=max(vp[j-1],vp[j]);

                hs[x]=max(suff[x][y],hs[x]);
                if(x!=n-1)hs[x]=max(hs[x+1],hs[x]);
                vs[y]=max(suff[x][y],vs[y]);
                if(y!=m-1)vs[y]=max(vs[y+1],vs[y]);
            }
        }
        int len=0;
        for(int i=0;i<n-1;i++){
            len=max(len,min(hp[i],hs[i+1]));
        }
        for(int i=0;i<m-1;i++){
            len=max(len,min(vp[i],vs[i+1]));
        }
        return 2*len*len;
    }
};
int main() {
    freopen("00_input.txt", "r", stdin);
    freopen("00_output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;
    cout<<obj.maximumAreaOfDisjointSquares(grid)<<endl;
    return 0;
}