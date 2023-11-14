class Solution {

public:
    int minimumSum(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>prefix(n);
        vector<int>suffix(n);

        int ans = 1e9;

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++)
        {
            prefix[i] = min(prefix[i-1],nums[i]);
            suffix[n-i-1] = min(suffix[n-i],nums[n-i-1]);
        }    

        for(int i = 1 ; i < n-1 ; i++)
        {
            if(prefix[i-1] < nums[i] && suffix[i+1] < nums[i])
            {
                ans = min(ans,prefix[i-1]+suffix[i+1]+nums[i]);
            }
        }

        if(ans == 1e9)return -1;
        return ans;
    }
};