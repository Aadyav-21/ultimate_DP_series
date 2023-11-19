#include<iostream>
#include<limits.h>
#include<vector>
#include<unordered_map>
#define MOD 100000007
using namespace std;
//dp + decision making type question
//buy and sell stock using recursion
int pro(vector<int>&prices){
    int mini=prices[0];
    int profit=0;
    for(int i=1;i<prices.size();i++){
        int diff=prices[i]-mini;
        profit=max(profit,diff);
        mini=min(mini,prices[i]);
    }
    return profit;
};
//same problem -variant 2;
int solve(int index,int buy,vector<int>&prices){
    if(index==prices.size())return 0;
    int profit=0;
    if(buy){
        int b=-prices[index]+solve(index+1,0,prices);
        int s=0+solve(index+1,1,prices);
        profit=max(b,s);
    }
    else{
        int s=prices[index]+solve(index+1,1,prices);
        int sk=0+solve(index+1,0,prices);
        profit=max(s,sk);
    }
    return profit;
}
int maxpro(vector<int>&profit){
    return solve(0,1,prices);
}
//using memoization
int solveMem(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
    if(index==prices.size())return 0;
    if(dp[index][buy]!=-1)return dp[index][buy];
    int profit=0;
    if(buy){
        int b=-prices[index]+solveMem(index+1,0,prices,dp);
        int s=0+solveMem(index+1,1,prices,dp);
        profit=max(b,s);
    }
    else{
        int s=prices[index]+solveMem(index+1,1,prices,dp);
        int sk=0+solveMem(index+1,0,prices,dp);
        profit=max(s,sk);
    }
    return dp[index][buy]=profit;
}
int maxP(vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solveMem(0,1,prices,dp);
}
//using tabulation and optimising space
int solveTab(vector<int>&prices){
    int n=prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                int b=-prices[index]+next[0];
                int s=0+next[1];
                profit=max(b,s);
            }
            else{
                int sel=prices[index]+next[1];
                int skip=0+next[0];
                profit=max(sel,skip);
            }
            curr[buy]=profit;
        }
        next=curr;
    }
    return next[i];
}
//buy and sell stock-variant-3 using recursion(3d DP)
int sol(int index,int buy,vector<int>&prices,int limit){
    if(index==prices.size())return 0;
    if(limit==0)return 0;
    int profit=0;
    if(buy){
        int b=-prices[index]+solve(index+1,0,prices,limit);
        int s=0+solve(index+1,1,prices,limit);
        profit=max(b,s);
    }
    else{
        int s=prices[index]+solve(index+1,1,prices,limit-1);
        int sk=0+solve(index+1,0,prices,limit);
        profit=max(s,sk);
    }
    return profit;
}
int res(vector<int>&prices){
    return solve(0,1,prices,2);
}
//using tabulation
int so(vector<int>&prices){
    vector<vector<vector<int>>dp(n+1,vector<vector<int>>(2,vector<int(3,0)));
    int n=prices.size();
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit=0;
                if(buy){
                    b=-prices[index]+dp[index+1][0][limit];
                    int s=0+dp[index+1][1][limit];
                    profit=max(b,s);
                }
                else{
                    int sel=prices[index]+dp[index+1][1][limit-1];
                    int skip=0+dp[index+1][0][limit];
                    profit=max(sel,skip);
                }
                dp[index][buy][limit]=profit;
            }
        }
        return dp[0][1][2];
    }
}




