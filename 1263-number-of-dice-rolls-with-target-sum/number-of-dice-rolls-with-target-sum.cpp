class Solution {

    int m = 1e9+7;

    int f(int n,int k,int target,vector<vector<int>>&dp)
    {
        if(n == 0)return (target == 0);
        if(dp[n][target] != -1)return dp[n][target];

        int total_ways = 0;

        for(int i = 1 ; i <= k ; i++)
        {
            if(target >= i)
            {
                total_ways = (total_ways + f(n-1,k,target-i,dp))%m;
            }
        }

        return dp[n][target] = total_ways;
    }

public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,k,target,dp);    
    }
};