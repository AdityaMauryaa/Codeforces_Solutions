/*
Problem Statement
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4
[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <unistd.h>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    int operation=0;
    int dp[1000000];
    int flag=1;
    Solution(int check):flag(check){};
    int solve2(vector<vector<int>>&arr,int mask,int i){
        if(i==arr.size())return 0;
        int ans=INT_MAX;
        if(flag)
        if(dp[mask]!=-1)return dp[mask];
        operation++;
        for(int j=0;j<arr.size();j++){
            if((mask&(1<<j))==0){
                ans=min(ans,arr[i][j]+solve2(arr,mask | (1<<j),i+1));
            }
        }
        return dp[mask]=ans;
    }
    void solve(vector<vector<int>>&arr){
        memset(dp,-1,sizeof(dp));
       int ans=solve2(arr,0,0);
       if(flag)
       {
        cout<<"Operation required for this problem with memoization: "<<operation<<endl;
        cout<<"Answer for this problem with memoization: "<<ans<<endl;
    }
    else{
        cout<<"Operation required for this problem without memoization: "<<operation<<endl;
        cout<<"Answer for this problem without memoization: "<<ans<<endl;
        }

    }
};

int main(){
    vector<vector<int>> arr = {
        {63,17,42,11,78,96, 2,15,34,58,67,81, 4, 7,53,44,85,25},
        {91,55,19,36, 5,93,84,41,29,59,77,35,22,70,26,64, 3,10},
        { 8,57,16,22,14, 9,60,40,65,52,33,71,48, 1,95,54,18,87},
        {61,12,50,37,80,99,23, 6,68,27,75,31,45,90,24,13,38,72},
        {10, 4,82,46,34, 7,29,70,12,65,56,84,16,61,58,21,44, 3},
        {33,19,47,72, 1,89,26,92,35, 8,55, 5,41,62,83,48,31,97},
        {27,77, 9,60,66,11,73,50,59,18,42,93,85, 7,36,67,24,14},
        {52,39,24,68,87,75, 6,79,25,90, 4,81,30,64,91,99,10, 8},
        {32, 5,14,94,18,47,65,49,54,27,96,12, 1,70,21,58,31,34},
        {85,61,72,16,44,37,78,20,93, 9,88,67,56,13,50,83,47,62},
        {41,84, 3,25, 7,91,32,76,12,54,99,19,60,38,74, 8,17,40},
        {95,22,64,13,81,24,14,55,28,79,90,33,35,29,52, 0,58,71},
        {53,10, 1,92,70,36,68,44,83,17,26,49,42, 5,31,19,77, 8},
        {69,30,88, 2,63,58,80,93, 4,47,15,46,25,84, 7,34,59,39},
        {23,75,66,11, 9,61,40,59,86,20,14,38,50,10,33,91, 5,27},
        {35,94, 8,29,54,77,17,45,92, 3,79,24,69,41,26,90,13, 1},
        {76, 7,43,51,30,62,95,12, 2,85,22,37,31,64, 9,34,19,99},
        {18,73,28,81,67,23,21,60, 6,53,46,97,75,42,38, 0,91,70},
};
    
    Solution obj1(0); //without memoisation
    Solution obj2(1); //with memoisation
    obj1.solve(arr);
    obj2.solve(arr);
}