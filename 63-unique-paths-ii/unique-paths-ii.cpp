class Solution {
public:

    int f(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
    {
        if(i == 0 && j == 0)return 1;
        if(dp[i][j] != -1)return dp[i][j];

        int ans = 0;

        if(i > 0 && grid[i-1][j] == 0)ans+=f(grid,i-1,j,dp);
        if(j > 0 && grid[i][j-1] == 0)ans+=f(grid,i,j-1,dp);

        return dp[i][j]=ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)return 0;

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(obstacleGrid,n-1,m-1,dp);   
    }
};