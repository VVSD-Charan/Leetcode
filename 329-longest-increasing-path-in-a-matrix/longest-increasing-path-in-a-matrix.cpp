class Solution {

    int dx[4] = {-1,+1,0,0};
    int dy[4] = {0,0,-1,+1};

public:

    int dfs(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(dp[i][j] != -1)return dp[i][j];

        int ans = 0;

        for(int x = 0 ; x < 4 ; x++)
        {
            int cx = i + dx[x];
            int cy = j + dy[x];

            if(cx >= 0 && cy >= 0 && cx < matrix.size() && cy < matrix[0].size() && matrix[cx][cy] > matrix[i][j])
            {
                ans = max(ans , 1 + dfs(matrix,cx,cy,dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int max_path = 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(dp[i][j] == -1)
                {
                    max_path = max(max_path , 1 + dfs(matrix,i,j,dp));
                }
            }
        }

        return max_path;
    }
};