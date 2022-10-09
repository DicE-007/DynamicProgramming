//ques link https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
  //memoization
    int helper(int arr[],vector<int>&dp,int n){
        if(n==0)return arr[n];
        if(n<0) return 0;
        if(dp[n]!=-1)return dp[n];
        int pick = arr[n]+helper(arr,dp,n-2);
        int notpick = helper(arr,dp,n-1);
        return dp[n] = max(pick,notpick);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1) return arr[0];
        else if(n==2) return max(arr[0],arr[1]);
        else if(n==3) return arr[0]+arr[2];
        vector<int>dp(n,-1);
        //return helper(arr,dp,n);
        //tabulation
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int p=arr[i];if(i>1)p+=dp[i-2];
            int np = dp[i-1];
            dp[i]=max(p,np);
        }
        return dp[n-1];
        
    }
};
