#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//min score triangulation of polygon using recursion
int solve(vector<int>&v){
    if(i+1==j)return 0;
    int ans=INT16_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
    }
    return ans;
}
int score(vector<int>&val){
    int n=val.size();
    return solve(val,0,n-1);
}
//using memoisation
int solveMem(vector<int>&v,int i,int j,vector<vector<int>&dp){
    if(i+1==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT16_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[j]*v[k]+solveMem(v,i,k,dp)+solveMem(v,k,j,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int sc(vector<int>&val){
    int n=val.size();
    vector<vector<int>dp(n,vector<int>(n,-1));
    return solveMem(val,0,n-1,dp);
}
//using tabulation
int solveTab(vector<int>&v){
    int n=v.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
            int ans=INT16_MAX;
            for(int k=i+1;k<j;k++){
                ans=min(ans,v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1];
}
int minScore(vector<int>&val){
    int n=val.size();
    return solveTab(val);
}

