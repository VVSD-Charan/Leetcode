class Solution {

    int rev(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            sum = (sum * 10) + (n % 10);
            n = (n / 10);
        }

        return sum;
    }

public:
    int countNicePairs(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int pairs = 0;
        int mod = 1e9+7;

        for(auto it : nums)
        {
            int diff = it - rev(it);
            pairs = (pairs + mp[diff])%mod;

            mp[diff]++;
        }

        return pairs;
    }
};