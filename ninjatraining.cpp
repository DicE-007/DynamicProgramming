//ques link: https://www.codingninjas.com/codestudio/problem-details/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;
int recusrion(int i,int prev,vector<vector<int>>&points){
    if(i==0){
        int maxi = 0;
        for (int task = 0; task < 3;task++){
            if(task==prev)
                continue;
            else{
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int task = 0; task < 3;task++){
        if (task!=prev){
            int point = points[i][task] + recusrion(i - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int memoization(int n,vector<vector<int>> &points,int prev,vector<vector<int>>&dp){
    if(n==0){
        int maxi=0;
        for(int i=0;i<3;i++){
        if(i!=prev){
            int point = points[0][i];
            maxi=max(maxi,point);
        }
    }
    return maxi;
    }
    if(dp[n][prev]!=-1)return dp[n][prev];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=prev){
            int point = points[n][i]+memoization(n-1,points,i,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[n][prev]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return memoization(n-1,points,3,dp);
}



int main(){
    return 0;
}
