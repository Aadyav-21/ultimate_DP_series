#include<iostream>
#include<vector>
using namespace std;
//minimum cost climbing stairs using recursion
#define MOD 10000007
int solve(long long stairs,int i){
    //base case
    if(i==stairs)return 1;
    if(i>stairs)return 0;
    return (solve(stairs,i+1)+solve(stairs,i+2))%MOD;
}
int count(long long stairs){
    int ans=solve(stairs,0);
    return ans;
}
//solution using DP using memoization
int solve(vector<int>& cost,int n,vector<int>& dp){
    //base case
    if(n==0)return cost[0];
    if(n==1)return cost[1];
    if(dp[n]!=-1)return dp[n];
    dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return dp;
}
int minCost(vector<int>& cost){
    int n=cost.size();
    vector<int>dp(n+1,-1);
    int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
};
//using DP tabulation
int sol(vector<int>& cost,int n){
    //creation of dp array
    vector<int>dp(n+1);
    //base case analyse
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);    
    }
    return min(dp[n-1],dp[n-2]);
}
int minC(vector<int>& cost){
    int n=cost.size();
    return sol(cost,n);
}

