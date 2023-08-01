class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int counter = 0;
        int curr_sum = 0;

        map<int,int>mp;

        for(auto it : nums)
        {
            curr_sum += it;

            if(curr_sum == k)
            {
                counter++;
            }
            counter+=mp[curr_sum-k];
            
            mp[curr_sum]++;
        }

        return counter;    
    }
};