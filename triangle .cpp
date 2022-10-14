class Solution {
public:
    int solver(vector<vector<int>>arr,int i,int j,int k,vector<vector<int>>&dp){
        if(i==k)return arr[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int bot = arr[i][j]+solver(arr,i+1,j,k,dp);
        int diag = arr[i][j]+solver(arr,i+1,j+1,k,dp);
        return dp[i][j]=min(bot,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //return solver(triangle,0,0,i-1,dp);
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int bot = triangle[i][j]+dp[i+1][j];
                int dia = triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(bot,dia);
            }
        }
        return dp[0][0];
    }
};
