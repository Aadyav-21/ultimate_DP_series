#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//perfect squares or get minimum squares from a given no. N using recursion
int solve(int n){
    if(n==0)return 0;
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+solve(n-temp));
    }
    return ans;
}
int m(int n){
    return solve(n);
}
//using memoisation
int solveMem(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n!=-1])return dp;
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int temp=i*i;
        ans=min(ans,1+solveMem(n-temp,dp));
    }
    dp[n]=ans;
    return dp[n];
}
int dp(int n){
    vector<int>dp(n+1,-1);
    return solveMem(n,dp);
}
//using tabulation
int solveTab(int n){
    vector<int>dp(n+1,INT16_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp=j*j;
            if(i-temp>=0)
                dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
    return dp[i];
}
int answer(int n){
    return solveTab(int n);
}