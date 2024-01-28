class Solution {

    int getAll(vector<int>&row,int target)
    {
       int curr_sum = 0;
        int total_arrays = 0;

        map<int,int>mp;

        for(int i = 0 ; i < row.size() ; i++)
        {
            curr_sum = curr_sum + row[i];

            if(curr_sum == target)
            {
                total_arrays = total_arrays + 1;
            }

            if(mp.find(curr_sum - target) != mp.end())
            {
                total_arrays = total_arrays + mp[curr_sum - target];
            }

            mp[curr_sum]++;
        }
        return total_arrays;
    }

    int row_wise(vector<vector<int>>&matrix,int target,int r,int c)
    {
        int total_matrices = 0;

        for(int first_row = 0 ; first_row < r ; first_row++)
        {
            vector<int>col_sum(c,0);

            for(int last_row = first_row ; last_row < r ; last_row++)
            {
                for(int i = 0 ; i < c ; i++)
                {
                    col_sum[i] += matrix[last_row][i];
                }

                total_matrices += getAll(col_sum,target);
            }
        }

        return total_matrices;
    }

    int column_wise(vector<vector<int>>&matrix,int target,int r,int c)
    {
        int total_matrices = 0;

        for(int first_col = 0 ; first_col < c ; first_col++)
        {
            vector<int>row_sum(r,0);

            for(int last_col = first_col ; last_col < c ; last_col++)
            {
                for(int i = 0 ; i < r ; i++)
                {
                    row_sum[i] += matrix[i][last_col];
                }

                total_matrices += getAll(row_sum,target);
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
            return column_wise(matrix,target,r,c);
        }

        return row_wise(matrix,target,r,c);
    }
};