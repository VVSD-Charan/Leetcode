class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[0][0] > target || matrix[n-1][m-1] < target)return false;

        for(int i = 0 ; i < n ; i++)
        {
            if(matrix[i][0] <= target && matrix[i][m-1] >= target)
            {
                int lo = 0;
                int hi = m-1;

                while(hi - lo > 1)
                {
                    int mid = (lo + hi)>>1;

                    if(matrix[i][mid] == target)return mid;

                    if(matrix[i][mid] > target)
                    {
                        hi = mid;
                    }
                    else
                    {
                        lo = mid;
                    }
                }

                if(matrix[i][lo] == target || matrix[i][hi] == target)return true;
            }
        }    

        return false;
    }
};