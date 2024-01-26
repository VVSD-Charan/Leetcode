class Solution {

    int dr[4] = {-1,+1,0,0};
    int dc[4] = {0,0,-1,+1};
    int mod = 1e9+7;

    int dfs(int m,int n,int maxMove,int sr,int sc,vector<vector<vector<int>>>&dp)
    {
        if(maxMove < 0)return 0;
        if(sr < 0 || sc < 0 || sr >= m || sc >= n)return 1;
        if(dp[sr][sc][maxMove] != -1)return dp[sr][sc][maxMove];

        int total_paths = 0;

        for(int i = 0 ; i < 4 ; i++)
        {
            int cr = sr + dr[i];
            int cc = sc + dc[i];

            total_paths = ((total_paths + dfs(m,n,maxMove-1,cr,cc,dp))%mod);
        }

        return dp[sr][sc][maxMove] = total_paths;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return dfs(m,n,maxMove,startRow,startColumn,dp);    
    }
};