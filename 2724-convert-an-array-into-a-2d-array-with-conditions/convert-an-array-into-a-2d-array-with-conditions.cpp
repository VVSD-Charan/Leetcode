class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        int max_freq = 0;

        map<int,int>mp;

        for(int i = 0 ; i < nums.size() ;  i++)
        {
            max_freq = max(max_freq,++mp[nums[i]]);
        }

        vector<vector<int>>matrix(max_freq);

        for(auto it = mp.begin() ; it != mp.end() ; it++)
        {
            int row = 0;
            int freq = it->second;

            while(freq--)
            {
                matrix[row].push_back(it->first);
                row++;
            }
        }    

        return matrix;
    }
};