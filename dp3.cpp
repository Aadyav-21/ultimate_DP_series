#include<iostream>
#include<vector>
using namespace std;
//minimum number of coins for the given target using recursion
int solve(vector<int>&num,int x){
    if(x==0)return 0;
    if(x<0)return INT16_MAX;
    int mini=INT8_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i]);
        if(ans!=INT16_MAX)mini=min(mini,1+ans);
    }
    return mini;
}
int min(vector<int>&num,int x){
    int ans=solve(num,x);
    if(ans==INT16_MAX)return -1;
    return ans;
}
//using memoization
int sol(vector<int>&num,int x,vector<int>&dp){
    if(x==0)return 0;
    if(x<0)return INT16_MAX;
    if(dp[x]!=-1)return dp[x];
    int mini=INT8_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve(num,x-num[i]);
        if(ans!=INT16_MAX)mini=min(mini,1+ans);
    }
    dp[x]=mini;
    return mini;
}
int m(vector<int>&num,int x){
    vector<int>dp(x+1,-1);
    int ans=sol(num,x,dp);
    if(ans==INT_MAX)return -1;
    else return ans;
}
//using tabulation
int s(vector<int>&num,int x){
    vector<int>dp(x+1,INT16_MAX);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0&&dp[i-num[j]!=INT16_MAX]){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x]==INT16_MAX)return -1;
    return dp[x];
}
int mi(vector<int>&num,int x){
    return s(num,x);
}

