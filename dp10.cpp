#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//combination sum problem in an array using recursion
int solve(vector<int>&num,int tar){
    if(tar<0)return 0;
    if(tar==0)return 1;
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solve(num,tar-num[i]);
    }
    return ans;
}
int find(vector<int>&num,int tar){
    return solve(num,tar);
}
//using memoization
int solveMem(vector<int>&num,int tar){
    if(tar<0)return 0;
    if(tar==0)return 1;
    if(dp[tar]!=-1)return dp[tar];
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans+=solveMem(num,tar-num[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
}
int f(vector<int>&num,int tar){
    vector<int>dp(tar+1,-1);
    return solveMem(num,tar,dp);
}
//using tabulation
int solveTab(vector<int>&num,int tar){
    vector<int>dp(tar+1,0);
    dp[0]=1;
    //traversing from target 1 to tar
    for(int i=1;i<=tar;i++){
        //traversing on num vector
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0)
                dp[i]+=dp[i-num[j]];
        }
    }
    return dp[tar];
}
int g(vector<int>&num,int tar){
    return solveTab(num,tar);
}

