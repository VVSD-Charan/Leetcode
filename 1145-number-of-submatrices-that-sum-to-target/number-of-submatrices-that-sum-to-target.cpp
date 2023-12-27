class Solution {

    int numberTarget(vector<int>&row,int target)
    {
        int curr_sum = 0;
        int total_arrays = 0;
        int max_len = 0;

        map<int,int>mp;

        for(int i = 0 ; i < row.size() ; i++)
        {
            curr_sum += row[i];

            if(curr_sum == target)
            {
                total_arrays++;
            }

            if(mp.find(curr_sum - target) != mp.end())
            {
                total_arrays += mp[curr_sum - target];
            }

            mp[curr_sum]++;
        }
        return total_arrays;
    }

    int col_wise(vector<vector<int>>&matrix,int r,int c,int target)
    {

         int total_matrices = 0;
         for(int left_col = 0 ;  left_col < c ; left_col++)
        {
            vector<int>row_sum(r,0);

            for(int right_col = left_col ; right_col < c ; right_col++)
            {
                for(int i = 0 ; i < r ; i++)
                {
                    row_sum[i] += matrix[i][right_col];
                }

                total_matrices += numberTarget(row_sum,target);
            }
        }

        return total_matrices;
    }

     int row_wise(vector<vector<int>>&matrix,int r,int c,int target)
    {

         int total_matrices = 0;
         for(int first_row = 0 ;  first_row < r ; first_row++)
        {
            vector<int>col_sum(c,0);

            for(int last_row = first_row ; last_row < r ; last_row++)
            {
                for(int i = 0 ; i < c ; i++)
                {
                    col_sum[i] += matrix[last_row][i];
                }

                total_matrices += numberTarget(col_sum,target);
            }
        }

        return total_matrices;
    }

public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        
        if(r > c)
        {
            return col_wise(matrix,r,c,target);
        }
        return row_wise(matrix,r,c,target);
    }
};