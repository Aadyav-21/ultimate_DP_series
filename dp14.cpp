#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//2d dp question
//minimum sideways jump using recursion
int solve(vector<int>& obstacles,int currlane,int currpos){
    //base case
    int n=obstacles.size()-1;
    if(currpos==n)return 0;
    if(obstacles[currpos+1]!=currlane)return solve(obstacles,currlane,currpos);
    else{
        //sidewyas jump
        int ans=INT16_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obstacles[currpos]!=i)ans=min(ans,1+solve(obstacles,i,currpos));
        }
        return ans;
    }
}
int mini(vector<int>&obstacles){
    return solve(obstacles,2,0);
}
//using memoisation
int solveMem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>&dp){
    //base case
    int n=obstacles.size()-1;
    if(currpos==n)return 0;
    if(dp[currlane][currpos]!=-1)return dp[currlane][currpos];
    if(obstacles[currpos+1]!=currlane)return solveMem(obstacles,currlane,currpos,dp);
    else{
        //sidewyas jump
        int ans=INT16_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obstacles[currpos]!=i)ans=min(ans,1+solveMem(obstacles,i,currpos,dp));
        }
        dp[currlane][currpos]=ans;
        return dp[currlane][currpos];
    }
}
int res(vector<int>&obstacles){
    vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
    return solveMem(obstacles,2,0,dp);
}
//using tabulation
int solveTab(vector<int>&obstacles){
    int n=obstacles.size()-1;
    vector<vector<int>>dp(4,vector<int>(obstacles.size(),1e9));
    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;
    for(int currpos=n-1;currpos>=0;currpos--){
        for(int currlane=1;currlane<=3;currlane++){
            if(obstacles[currpos+1]!=currlane)return dp[currlane][currpos]=dp[currlane][currpos];
            else{
            //sidewyas jump
                int ans=1e9;
                for(int i=1;i<=3;i++){
                if(currlane!=i && obstacles[currpos]!=i)ans=min(ans,1+dp[i][currpos+1]);
            }       
            dp[currlane][currpos];
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
}
int s(vector<int>&obstacles){
    return solveTab(obstacles);
}
