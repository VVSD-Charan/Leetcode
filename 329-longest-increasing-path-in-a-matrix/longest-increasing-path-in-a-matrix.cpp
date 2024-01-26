class Solution {

    int di[4] = {-1,+1,0,0};
    int dj[4] = {0,0,-1,+1};

    int f(vector<vector<int>>&matrix,int i,int j,int n,int m,vector<vector<int>>&dp)
    {
        if(dp[i][j] != -1)return dp[i][j];

        int longest = 1;

        for(int k = 0 ; k < 4 ; k++)
        {
            int ci = i + di[k];
            int cj = j + dj[k];

            if(ci >= 0 && cj >= 0 && ci < n && cj < m)
            {
                if(matrix[ci][cj] > matrix[i][j])
                {
                    longest = max(longest , 1 + f(matrix,ci,cj,n,m,dp));
                }
            }
        }

        return dp[i][j] = longest;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int max_path = 1;

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                max_path = max(max_path , f(matrix,i,j,n,m,dp));
            }
        }   

        return max_path;
    }
};