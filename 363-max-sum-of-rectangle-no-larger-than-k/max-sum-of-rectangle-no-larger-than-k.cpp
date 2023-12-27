class Solution {

    int getMax(vector<int>&arr,int k)
    {
       int curr_sum = 0;
       int max_sum = INT_MIN;

       set<int>s;
       s.insert(0);

       for(auto it : arr)
       {
           curr_sum += it;

           auto i = s.lower_bound(curr_sum - k);

           if(i != s.end())
           {
               max_sum = max(max_sum , curr_sum - *i);
           }
           s.insert(curr_sum);
       }

       return max_sum;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int max_sum = INT_MIN;

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int first_row = 0 ; first_row < rows ; first_row++)
        {
            vector<int>col_sum(cols,0);

            for(int last_row = first_row ; last_row < rows ; last_row++)
            {
                for(int i = 0 ; i < cols ; i++)
                {
                    col_sum[i] += matrix[last_row][i];
                }

                max_sum = max(max_sum,getMax(col_sum,k));
            }
        }

        return max_sum;
    }
};