#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//minimum cost for tickets
//using tbaultion method but space optimised way
//use of queue data structure
int cost(int n,vector<int>days,vector<int>cost){
    int ans=0;
    queue<pair<int,int>>month;
    queue<pair<int,int>>week;
    for(int day:days){
        //remove expired days
        while(!month.empty()&&month.front().first+30<=day){
            month.pop();
        }
        while(!week.empty()&&week.front().first+7<=day){
            week.pop();
        }
        //add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));
        //ans update
        ans=min(ans+cost[0],min(week.front().second,month.front().seocnd));
    }
    return ans;
}
//largest square area -2D DP using recursion
int solve(vector<vector<int>>&mat,int i,int j,int&maxi){
    if(i>=mat.size()||j>=mat[0].size())return 0;
    int right=solve(mat,i,j+1,maxi);
    int dia=solve(mat,i+1,j+1,maxi);
    int down=solve(mat,i+1,j,maxi);
    if(mat[i][j==1]){
        int ans=1+min(right,min(diagonal,down));
        maxi=max(maxi,ans);
        return ans;
    }
    else return 0;
}
int sq(int n,int m,vector<vector<int>>mat){
    int maxi=0;
    solve(mat,0,0,maxi);
    return maxi;
}
//using memoization
int solveMem(vector<vector<int>>mat,int i,int j,int&maxi,vector<vector<int>>&dp){
    if(i>=mat.size()||j>=mat[0].size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int right=solveMem(mat,i,j+1,maxi,dp);
    int dia=solveMem(mat,i+1,j+1,maxi,dp);
    int down=solveMem(mat,i+1,j,maxi,dp);
    if(mat[i][j==1]){
        dp[i][j]=1+min(right,min(diagonal,down));
        maxi=max(maxi,dp[i][j]);
        return dp[i][j];
    }
    else return dp[i][j]=0;
}
int calc(int n,int m,vector<vector<int>>mat){
    int maxi=0;
    vector<vector<int>>dp(n,vec'<int>(m,-1));
    solveMem(mat,0,0,maxidp);
    return maxi;
}
//using tabulation
int solveTab(vector<vector<int>>&mat,int &maxi){
    int row=mat.size();
    int col=mat[0].size();
    vector<vector<int>>dp(row+1,vector<int>(col+1,0));
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=dp[i][j+1];
            int dia=dp[i+1][j+1];
            int down=dp[i+1][j];
            if(mat[i][j==1]){
                dp[i][j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,dp[i][j]);
            }
            else  dp[i][j]=0;
        }
    }
    return dp[0][0];
}
int res(int n,int m,vector<vector<int>>mat){
    int maxi=0;
    solveTab(mat,maxi);
    return maxi;
}
//space optimisation
int sol(vector<vector<int>>&mat,int &maxi){
    int row=mat.size();
    int col=mat[0].size();
    vector<int>curr(col+1,0);
    vector<int>next(col+1,0);
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int right=curr[j+1];
            int dia=next[j+1];
            int down=next[j];
            if(mat[i][j==1]){
                curr[j]=1+min(right,min(diagonal,down));
                maxi=max(maxi,curr[j]);
            }
            else  curr[j]=0;
        }
        next=curr;
    }
    return next[0];
}
int see(int n,int m,vector<vector<int>>mat){
    int maxi=0;
    sol(mat,maxi);
    return maxi;
}

