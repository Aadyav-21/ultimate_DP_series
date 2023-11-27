#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//number of dice rolls with target sum using recursion
long long solve(int dice,int faces,int target){
    //base case
    if(target<0)return 0;
    if(dice==0 && target !=0)return 0;
    if(dice==0 && target==0)return 1;
    long long ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solve(dice-1,faces,target-i);
    }
    return ans;
}
long long ways(int m,int n,int x){
    return solve(n,m,x);
}
//using memoisation
long long solveMem(int dice,int faces,int target,vector<vector<long long>>&dp){
    //base case
    if(target<0)return 0;
    if(dice==0 && target !=0)return 0;
    if(dice==0 && target==0)return 1;
    if(dp[dice][target]!=-1)return dp[dice][target];
    long long ans=0;
    for(int i=1;i<=faces;i++){
        ans=ans+solveMem(dice-1,faces,target-i,dp);
    }
    return dp[dice][target]=ans;
}
long long way(int m,int n,int x){
    vector<vector<long long>>dp(d+1,vector<long long>(x+1,-1));
    return solveMem(n,m,x,dp);
}
//using tabulation
long long solveTab(int d,int f,int t){
    vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
    //after analysing base case
    dp[0][0]=1;
    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
            long long ans=0;
            for(int i=1;i<=f;i++){
                if(target-i>=0)
                    ans=ans+dp[dice-1][target-i];
            }
            dp[dice][target]=ans;
        }
    }
    return dp[d][t];
}
long long res(int m,int n,int x){
    return solveTab(n,m,x);
}
//optimising space
long sol(int d,int faces,int t){
    vector<long long>prev(t+1,0);
    vector<long long>curr(t+1,0);
    prev[0]=1;
    for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
            long long ans=0;
            for(int i=1;i<=faces;i++){
                if(target-i>=0)
                    ans=ans+prev[target-i];
            }
            curr[target]=ans;
        }
        prev=curr;
    }
    return prev[t];
}
long long result(int m,int n,int x){
    return sol(n,m,x);
}
//pascal trriangle problem solution using DP
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1);
            
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp[j]=1;
                }
                else{
                    temp[j]=(ans[i-1][j-1]+ans[i-1][j]);
                }
                
            }
                ans.push_back(temp);
                temp.clear();
        }
        return ans;
    }
};