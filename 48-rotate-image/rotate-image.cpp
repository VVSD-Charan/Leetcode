class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        } 

        for(int i=0;i<n;i++)
        {
            int lo = 0;
            int hi = n-1;

            while(lo<hi)
            {
                swap(matrix[i][lo],matrix[i][hi]);
                lo++;   hi--;
            }
        }   
    }
};