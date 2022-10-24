#include <bits/stdc++.h> 

// bool f(int n,int target,vector<int>arr,vector<vector<int>>&dp){
//     if(target==0)return true;
//     if(n==0) return (arr[0]==target);
//     if(dp[n][target]!=-1)return dp[n][target];
//     bool notTake = f(n-1,target,arr,dp);
//     bool take = false;
//     if(arr[n]<=target){
//         take = f(n-1,target-arr[n],arr,dp);
//     }
//     return dp[n][target]=notTake||take;
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notTake  = dp[i-1][j];
            bool take = false;
            if(arr[i]<=j){
                take  = dp[i-1][j-arr[i]];
            }
            dp[i][j]=take||notTake;
        }
    }
    return dp[n-1][k];
}
