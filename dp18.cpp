#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//partition equal subset sum using recursion
bool solve(int index,int arr[]int n,int tar){
    if(index>=n)return 0;
    if(tar<0)return 0;
    if(tar==0)return 1;
    bool incl=solve(index+1,arr,n,tar-arr[index]);
    bool excl=solve(index+1,arr,n,tar-0);
    return incl or excl;
}
int equal(int n,int arr[]){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    if(total & 1)return 0;
    int tar=total/2;
    return solve(0,arr,tar);
}
//using memoisation
bool solveMem(int index,int arr[],int n,int tar,vector<vector<int>>&dp){
    if(index>=n)return 0;
    if(tar<0)return 0;
    if(tar==0)return 1;
    if(dp[index][tar]!=-1)return dp[index][tar];
    bool incl=solve(index+1,arr,n,tar-arr[index]);
    bool excl=solve(index+1,arr,n,tar-0);
    return dp=[index][tar]= incl or excl;
}
 int par(int n,int arr[]){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    if(total & 1)return 0;
    int tar=total/2;
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return solveMem(0,arr,n,tar,dp);
 }
 //using tabulation
bool solveTab(int n,int arr[],int total){
    vector<vector<int>>dp(n+1,vector<int>(total+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int index=n-1,index>=0;index--){
        for(int tar=0;tar<=total/2;tar++){
            bool incl=0;
            if(tar-arr[index]>=0)incl=dp[index+1][tar-arr[index]];
            bool excl=dp[index+1][tar-0];
            dp[index][tar]=incl or excl;
        }
    }
    return dp[0][total/2];
}
int part(int n,int arr[]){
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    if(total & 1)return 0;
    int tar=total/2;
    return solveMem(n,arr,total);
}
//optimising space
bool sol(int n,int arr[],int total){
    vector<int>curr(total/2+1,0);
    vector<int>next(total/2+1,0);
    curr[0]=1;
    next[0]=1;
    for(int index=n-1,index>=0;index--){
        for(int tar=0;tar<=total/2;tar++){
            bool incl=0;
            if(tar-arr[index]>=0)incl=next[tar-arr[index]];
            bool excl=next[tar-0];
            curr[tar]=incl or excl;
        }
        next=curr;
    }
    return next[total/2];
}   
 