#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//0/1 knapsack problem using recursion
int solve(vector<int>&weight,vector<unt>& val,int index,int w){
    //base case
    //if only 1 item to steal ,then just compare its weight with the knapsack capacity
    if(index==0){
        if(weight[0]<=capacity)return val[0];
        else return 0;
    }
    int include=0;
    if(weight[index]<=capacity){
        include=val[index]+solve(weight,val,index-1,capacity-weight[index]);
    }
    int exclude=0+solve(weight,val,index-1,capacity);
    int ans=max(exclode,include);
    return ans;
}
int knapsack(vector<int>weight,vector<int>val,int n,int maxWeight){
    return solve(weight,val,index-1,maxWeight);
}
//using memoization
int solveMem(vector<int>&weight,vector<unt>& val,int index,int w,vector<vector<int>>&dp){
    //base case
    //if only 1 item to steal ,then just compare its weight with the knapsack capacity
    if(index==0){
        if(weight[0]<=capacity)return val[0];
        else return 0;
        if(dp[index][capacity]!=-1)return dp[index][capacity];
    }
    int include=0;
    if(weight[index]<=capacity){
        include=val[index]+solveMem(weight,val,index-1,capacity-weight[index],dp);
    }
    int exclude=0+solveMem(weight,val,index-1,capacity,dp);
    dp[index][capacity]=max(exclode,include);
    return dp[index][capacity];
}
int knap(vector<int>weight,vector<int>val,int n,int maxWeight){
    //return solve(weight,val,n-1,maxWeight);
    vector<vector<int>>dp(n,vector<int>maxWeight+1,-1);return solveMem(weight,val,n-1,maxWeight,dp);

}
//using tabulation
int solveTab(vector<int>&weight,vector<unt>& val,int index,int w){
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity)dp[0][w]=val[0];
        else dp[0][w]=0;
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;
            if(weight[index]<=w){
                include=val[index]+dp[index-1],[capacity-weight[index]];
            }
            int exclude=0+dp[index-1][w];
            dp[index][w]=max(exclude,include);
        }
    }
    return dp[n-1][capacity];
}
int knaps(vector<int>weight,vector<int>val,int n,int maxWeight){
    return solveTab(weigth,val,n,maxWeight);
}



