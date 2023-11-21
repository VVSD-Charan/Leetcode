class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        long long n = nums.size();
        long long totalPairs = (n*(n-1))/2;
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++)
        {
            if(mp.find(i-nums[i])!=mp.end())
            {
                totalPairs -= mp[i - nums[i]];
            }

            mp[i-nums[i]]++;
        }    

        return totalPairs;
    }
};