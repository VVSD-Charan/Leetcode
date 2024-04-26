class Solution {
public:
    
    int f(vector<vector<int>>&grid,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i == n-1)return grid[i][j];
        if(dp[i][j] != -1)return dp[i][j];

        int min_sum = INT_MAX;

        for(int x = 0 ; x < n ; x++)
        {
            if(x == j)continue;
            min_sum = min(min_sum,grid[i][j] + f(grid,i+1,x,n,dp));
        }

        return dp[i][j] = min_sum;
    }

    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        int min_sum = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            min_sum = min(min_sum ,f(grid,0,i,n,dp));
        }    

        return min_sum;
    }
};