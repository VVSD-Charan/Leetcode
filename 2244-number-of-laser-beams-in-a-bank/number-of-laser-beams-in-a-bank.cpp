class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int n = bank.size();
        int m = bank[0].size();

        vector<int>row_sum(n,0);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                row_sum[i] = row_sum[i] + (bank[i][j] == '1');
            }
        }

        int total_beams = 0;
        int prev_beams = 0;


        for(int i = 0 ; i < n ; i++)
        {
            if(row_sum[i] == 0)continue;

            total_beams = total_beams + (prev_beams * row_sum[i]);
            prev_beams = row_sum[i];
        }    

        return total_beams;
    }
};