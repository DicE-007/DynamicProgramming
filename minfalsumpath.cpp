class Solution {
public:
    int helper(int i,int j,vector<vector<int>>arr,int n,vector<vector<int>>&dp){
        if(j<0 || j>n) return 1e9;
        if(i==n){
            return arr[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ld = arr[i][j]+helper(i+1,j-1,arr,n,dp);
        int rd = arr[i][j]+helper(i+1,j+1,arr,n,dp);
        int dd = arr[i][j]+helper(i+1,j,arr,n,dp);
        return dp[i][j]=min(ld,min(rd,dd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = 1e9;
        // for(int i=0;i<n;i++){
        //     ans=min(ans,helper(0,i,matrix,n-1,dp));
        // }
        // return ans;
        //tabulation
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=1e9,ld=1e9,rd=1e9;
                 up = matrix[i][j]+dp[i-1][j];
                if(j-1>=0)
                     ld = matrix[i][j]+dp[i-1][j-1];
                else  ld = 1e9;
                if(j+1<n)
                     rd = matrix[i][j]+dp[i-1][j+1];
                else  rd = 1e9;
                dp[i][j]=min(ld,min(up,rd));
            }
        }
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
