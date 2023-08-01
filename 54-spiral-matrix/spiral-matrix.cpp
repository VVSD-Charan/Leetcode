class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int>arr;

        int lr = 0;
        int lc = 0;
        int hr = matrix.size()-1;
        int hc = matrix[0].size()-1;
        int total = (matrix.size()*matrix[0].size());
        int i = 0;

        while(total)
        {
            while(total!=0 && i<=hc)
            {
                arr.push_back(matrix[lr][i]);
                i++;   total--;
            }
            lr++;
            i=lr;

            while(total!=0 && i<=hr)
            {
                arr.push_back(matrix[i][hc]);
                i++;   total--;
            }
            hc--;
            i=hc;

            while(total!=0 && i>=lc)
            {
                arr.push_back(matrix[hr][i]);
                i--;   total--;
            }
            hr--;
            i=hr;

            while(total!=0 && i>=lr)
            {
                arr.push_back(matrix[i][lc]);
                i--;  total--;
            }
            lc++;
            i=lc;
        }   

        return arr; 
    }
};