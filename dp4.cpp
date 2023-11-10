#include<iostream>
#include<vector>
using namespace std;
//maximum sum of non adjacent elements using recursion
int solver(vector<int>&nums,int n){
    if(n<0)return 0;
    if(n==0)return nums[0];
    int inc=solver(nums,n-2)+nums[n];
    int exc=solver(nums,n-1)+0;
    return max(inc,exc);
}
int maxi(vector<int>&nums){
    int n=nums.size();
    int ans=solver(nums,n-1);
    return ans;
}
//using memoisation
int solve(vector<int>&nums,int n,vector<int>&dp){
    if(n<0)return 0;
    if(n==0)return nums[0];
    if (dp[n]!=-1)return dp[n];
    int inc=solver(nums,n-2)+nums[n];
    int exc=solver(nums,n-1)+0;
    dp[n]=max(inc,exc);
    return dp[n];
}
int m(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return m(nums,n-1,dp);
}
//using tabulation
int sol(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int show(vector<int>&nums){
    return sol(nums);
}