class Solution {
public:

    bool safe(vector<vector<int>>&matrix,int r,int c,int n)
    {
        int row = r;
        int col = c;

        while(row >= 0 && col >= 0)
        {
            if(matrix[row][col] != -1)return false;
            row--;
            col--;
        }

        row = r;
        col = c;

        while(col >= 0)
        {
            if(matrix[row][col] != -1)return false;
            col--;
        }

        row = r;
        col = c;

        while(row < n && col >= 0)
        {
            if(matrix[row][col] != -1)return false;
            row++;
            col--;
        }

        return true;
    }

    int f(vector<vector<int>>&matrix,int n,int col)
    {
        if(col == n)return 1;

        int ans = 0;
        
        for(int row = 0 ; row < n ; row++)
        {
            if(safe(matrix,row,col,n))
            {
                matrix[row][col] = 1;
                ans += f(matrix,n,col+1);
                matrix[row][col] = -1;
            }
        }

        return ans;
    }

    int totalNQueens(int n) 
    {
        vector<vector<int>>matrix(n,vector<int>(n,-1));

        return f(matrix,n,0);    
    }
};