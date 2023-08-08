class Solution {
public:

    int mod = 1e9 + 7;

    int f(vector<vector<int>>&grid, int i, int j,int k,int sum,vector<vector<vector<int>>>&dp)
    {
        if(i == 0 && j == 0)return (sum%k == 0);
        if(dp[i][j][sum] != -1)return dp[i][j][sum];

        long long ans = 0;

        if(i > 0)ans = (ans + f(grid,i-1,j,k,(sum + grid[i-1][j])%k,dp))%mod;
        if(j > 0)ans = (ans + f(grid,i,j-1,k,(sum + grid[i][j-1])%k,dp))%mod;

        return dp[i][j][sum] = (ans%mod);
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return f(grid,n-1,m-1,k,(grid[n-1][m-1]%k),dp);    
    }
};