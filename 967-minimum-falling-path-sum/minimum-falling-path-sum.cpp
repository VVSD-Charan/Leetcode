class Solution {

    int dx[3] = {+1,+1,+1};
    int dy[3] = {-1,0,+1};

    int f(vector<vector<int>>&matrix,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i == n-1)return matrix[i][j];
        if(dp[i][j] != 1e9)return dp[i][j];

        int min_path = INT_MAX;

         for(int a = 0 ; a < 3 ; a++)
         {
             int cx = i + dx[a];
             int cy = j + dy[a];

             if(cx >= 0 && cy >= 0 && cx < n && cy < n)
             {
                 min_path = min(min_path,f(matrix,cx,cy,n,dp));
             }
         }

         return dp[i][j] = matrix[i][j] + min_path;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int min_sum = INT_MAX;

        vector<vector<int>>dp(n,vector<int>(n,1e9));

        for(int i = 0 ; i < n ; i++)
        {
           min_sum = min(min_sum,f(matrix,0,i,n,dp));
        }

        return min_sum;    
    }
};