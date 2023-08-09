class Solution {
public:

    int f(vector<vector<int>>&grid,int i1,int j1,int i2,int j2,int n,vector<vector<vector<vector<int>>>>&dp)
    {
        if(i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0 )return -1e7;
        if(i1 == n || j1 == n || i2 == n || j2 == n)return -1e7;
        if(grid[i1][j1] == -1 || grid[i2][j2] == -1)return -1e7;
        if(i1 == n-1 && j1 == n-1 && i2 == n-1 && j2 == n-1)return grid[i1][j1];
        if(dp[i1][j1][i2][j2] != -1)return dp[i1][j1][i2][j2];

        int move1 = f(grid,i1+1,j1,i2+1,j2,n,dp);
        int move2 = f(grid,i1+1,j1,i2,j2+1,n,dp);
        int move3 = f(grid,i1,j1+1,i2,j2+1,n,dp);
        int move4 = f(grid,i1,j1+1,i2+1,j2,n,dp);

        if(i1 == i2 && j1 == j2)
        {
            return dp[i1][j1][i2][j2] = grid[i1][j1] + max(max(move1,move2),max(move3,move4));
        }

        return dp[i1][j1][i2][j2] = grid[i1][j1] + grid[i2][j2] + max(max(move1,move2),max(move3,move4));
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,f(grid,0,0,0,0,n,dp));    
    }
};