class Solution {

    int f(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(amount == 0)return 0;
        if(idx < 0)return 1e6;
        if(dp[idx][amount] != -1)return dp[idx][amount];

        if(coins[idx] <= amount)
        {
            int pick = 1 + f(coins,amount-coins[idx],idx,dp);
            int dontPick = f(coins,amount,idx-1,dp);

            return dp[idx][amount] = min(pick,dontPick);
        }

        return dp[idx][amount] =  f(coins,amount,idx-1,dp);
    }

public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = f(coins,amount,coins.size()-1,dp);

        if(ans >= 1e6)return -1;
        return ans;
    }
};