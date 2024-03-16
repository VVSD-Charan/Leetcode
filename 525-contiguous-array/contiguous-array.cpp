class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        map<int,int>mp;

        int ones = 0;
        int zeroes = 0;
        int max_length = 0;

        mp[0] = -1;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            ones += (nums[i] == 1);
            zeroes += (nums[i] == 0);

            int diff = ones - zeroes;
            
            if(mp.find(diff) != mp.end())
            {
                max_length = max(max_length,i-mp[diff]);
            }
            else
            {
                mp[diff] = i;
            }
        }    

        return max_length;
    }
};