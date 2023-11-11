#include<iostream>
#include<vector>
using namespace std;
//house robbery problem
long long int solve(vector<int>&nums){
    int n=nums.size();
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1;i<n;i++){
        long long int inc=prev2+nums[i];
        long long int exc=prev1+0;
        long long int ans=max(inc,exc);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int robber(vector<int>&val){
    int n=val.size();
    if(n==1)return val[0];
    vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1)frist.push_back(val[i]);
        if(i!=0)second.push_back(val[i]);
    }
    return max(solve(first),solve(second));
}