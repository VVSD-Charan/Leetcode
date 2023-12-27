class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int curr_sum = 0;
        map<int,int>mp;

        int total_arrays = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            curr_sum = curr_sum + nums[i];

            if(curr_sum == k)
            {
                total_arrays++;
            }

            if(mp.find(curr_sum - k) != mp.end())
            {
                total_arrays += mp[curr_sum-k];
            }
            mp[curr_sum]++;
        }

        return total_arrays;    
    }
};