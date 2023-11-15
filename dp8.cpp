#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//painting fence using recursion
int add(int a,int b){
    return (a%MOD+b%MOD)%MOD;
} 
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD)%MOD);
}
int solve(int n,int k){
    if(n==1)return k;
    if(n==2)return add(k,mul(k,k-1));
    int ans=add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
int numOfWay(int n,int k){
    return solve(n,k);
}
//using memoisation
int sol(int n,int k,vector<int>&dp){
    if(n==1)return k;
    if(n==2)return add(k,mul(k,k-1));
    if(dp[n]!=-1)return dp[n];
    int dp[n]=add(mul(sol(n-2,k,dp),k-1),mul(sol(n-1,k,dp),k-1));
    return dp[n];
}    
int way(int n,int k){
    vector<int>dp(n+1,-1);
    return sol(n,k,dp);
}
// using tabulation
int s(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int ways(int n,int k){
    return s(n,k);
}
//optimising space
int st(int n,int k){
    int prev2=k;
    int prev1=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int numway(int n,int k){
    return st(n,k);
}