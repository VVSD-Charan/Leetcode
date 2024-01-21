class Solution {

    int f(vector<int>&nums,int idx,vector<int>&dp)
    {
        if(idx < 0)return 0;
        if(dp[idx] != -1)return dp[idx];

        int pick = nums[idx] + f(nums,idx-2,dp);
        int dont_pick = f(nums,idx-1,dp);

        return dp[idx] = max(pick,dont_pick);
    }

public:
    int rob(vector<int>& nums) 
    {

        vector<int>dp(nums.size(),-1);

        return f(nums,nums.size()-1,dp);    
    }
};