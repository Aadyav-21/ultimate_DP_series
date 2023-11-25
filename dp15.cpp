#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//2d problem
//reducing dishes problem using recursion
int solve(vector<int>&sat,int idx,int time){
    //base case
    if(idx==sat.size())return 0;
    int include=sat[idx]*(time+1)+solve(sat,idx+1,time+1);
    int exclude=0+solve(sat,idx+1,time);
    return max(include,exclude);
}
int maxsat(vector<int>&sat){
    sort(sat.begin(),sat.end());
    return solve(sat,0,0);
}
//using memoization
int solveMem(vector<int>&sat,int idx,int time,vector<vector<int>>&dp){
    //base case
    if(idx==sat.size())return 0;
    if(dp[idx][time]!=-1)return dp[idx][time];
    int include=sat[idx]*(time+1)+solveMem(sat,idx+1,time+1,dp);
    int exclude=0+solveMem(sat,idx+1,time,dp);
    return dp[idx][time]=max(include,exclude);
}
int res(vector<int>&sat){
    sort(sat.begin(),sat.end());
    int n=sat.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solveMem(sat,0,0,dp);
}
//using tabulation
int solveTab(vector<int>&sat){
    int n=sat.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1;idx>=0;idx--){
        for(int time=idx;time>=0;time--){
            int include=sat[idx]*(time+1)+dp[idx+1][time+1];
            int exclude=0+dp[idx][time];
        }
    }
    return dp[0][0];
}
int res(vector<int>&sat){
    sort(sat.begin(),sat.end());
    int n=sat.size();
    return solveTab(sat);
}
//space optimisation=O(n)space but can also be done in O(1)space
int so(vector<int>&sat){
    int n=sat.size();
    vector<int>curr(n+1,0);
    vector<int<next(n+1,0);
    for(int idx=n-1;idx>=0;idx--){
        for(int time =idx;time>=0;time--){
            int include=sat[idx]*(time+1)+next[time+1];
            int exclude=0+next[time];
            curr[time]=max(include,exclude);
        }
        next=curr;
    }
    return next[0];
}
int mainf(vector<int>&sat){
    sort(sat.begin(),sat.end());
    int n=sat.size();
    return so(sat);
};
//length of longest increasing subsequence using recursion
int solve(int n,int a[],int curr,int prev){
    //base case
    if(curr==n)return 0;
    //include
    int take=0;
    if(prev==-1||a[curr]>a[prev])tkae=1+solve(n,a,curr+1,curr);
    //exclude
    int notTake=0+solve(n,a,curr+1,prev);
    return max(take,notTake);
}
int longest(int n,int a[]){
    return solve(n,a,0,-1);
}
//using memoization
int solveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
    //base case
    if(curr==n)return 0;
    if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
    //include
    int take=0;
    if(prev==-1||a[curr]>a[prev])take=1+solveMem(n,a,curr+1,curr,dp);
    //exclude
    int notTake=0+solveMem(n,a,curr+1,prev,dp);
    return dp[curr][prev+1]=max(take,notTake);
}
int result(int n,int a[]){
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solveMem(n,a,0,-1,dp);
}  
//using tabulation
int solveTab(int n,int a[]){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){
            int take=0;
            if(prev==-1||a[curr]>a[prev])take=1+dp[curr+1][curr+1];
            int notTake=0+dp[curr+1][prev+1];
            dp[curr][prev+1]=max(take,notTake);
        }
    }
    return dp[0][0];
}
int s(int n,int a[]){
    return solveTab(n,a);
}
int solveOptimal(int n,int a[]){
    if(n==0)return 0;
    vector<int>ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>ans.back())ans.push_back(a[i]);
        else{
        //find index of just bda element in ans
        int index=lower_bound(ans.begin(),ans.end(),a[i]-ans.begin());
        ans[index]=a[i];
        }
    }
    return ans.size();
}   
int show(int n,int a[]){
    return solveOptimal(n,a);
} 
