class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        long long n = nums.size();
        long long totalPairs = (n*(n-1))/2;
        map<int,int>mp;

        for(int i = 0 ; i < n ; i++)
        {
            totalPairs -= mp[i - nums[i]];
            mp[i-nums[i]]++;
        }    

        return totalPairs;
    }
};