#include<iostream>
#include<limits.h>
#include<vector>
#define MOD 100000007
using namespace std;
//maximum height by stacking cuboids
bool check(vector<int>base,vector<int>newbox){
    if(newbox[0]<=base[0]&&newbox[1]<=base[1]&&newbox[2]<=base[2]) return true;
    else return false;
}
int solveOptimal(int n,vector<vector<int>>& a){
   vector<int>row(n+1,0);
   vector<int>col(n+1,0);
   for(int curr=n-1;curr>=0;curr--){
        for(int prev =curr-1;prev>=-1;prev--){
            //include
            int take=0;
            if(prev==-1||check(a[curr],a[prev]))take=a[curr][2]+col[curr+1];
            //exclude
            int nottake=0+col[prev+1];
            row[prev+1]=max(take,nottake);
        }
        col=row;
   }
   return col[0];
}
int maxheight(vector<vector<int>>&cuboids){
    for(auto &a:cuboids){
        sort(a.begin(),a.end());
    }
    sort(cuboids.begin(),cuboids.end());
    return solveOptimal(cuboids.size(),cuboids);
}
//pizza with 3n slices -2D DP using recursion
int solve(int index,int end,vector<int>&slices,int n){
    if(n==0||index>end)return 0;
    int take=slices[index]+solve(index+2,end,slices,n-1);
    int not=0+solve((index+1,end,slices,n));
    return max(tkae,not);
}
int maxsize(vector<int>&slices){
    int k=slices.size();
    int case1=solve(0,k-2,slices,k/3);
    int case2=solve(1,k-1,slices,k/3);
    return max(case1,case2);
}
//using memoization
int solveMem(int index,int end,vector<int>&slices,int n,vector<vector<int>>&dp){
    if(n==0||index>end)return 0;
    if(dp[index][n]!=-1)return dp[index][n];
    int take=slices[index]+solveMem(index+2,end,slices,n-1,dp);
    int not=0+solveMem((index+1,end,slices,n,dp));
    return dp[index][n]=max(take,not);
}
int maxS(vector<int>&slices){
    int k=slices.size();
    vector<vector<int>>dp1(k+2,vector<int>(k,-1));
    int case1=solveMem(0,k-2,slices,k/3,dp1);
    vector<vector<int>>dp2(k+2,vector<int>(k,-1));
    int case2=solveMem(1,k-1,slices,k/3,dp2);
    return max(case1,case2);
}
//using tabulation
int solveTab(vector<int>&slices){
    int k=slices.size();
    vector<vector<int>>dp1(k,vector<int>(k,0));
    vector<vector<int>>dp1(k,vector<int>(k,0));
    for(int index=k-2;index>=3;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index]+dp[index+2][n-1];
            int not=0+dp1[index+1][n];
            dp[index][n]=max(take,not);
        }
    }
    int case1=dp1[0][k/3];
    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){
            int take=slices[index]+dp[index+2][n-1];
            int not=0+dp1[index+1][n];
            dp[index][n]=max(take,not);
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2);
}
int res(vector<int>&slices){
    return solveTab(slices);
}
 
    