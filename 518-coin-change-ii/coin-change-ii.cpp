class Solution {
public:

    int f(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(amount == 0)return 1;
        if(idx < 0)return 0;
        if(dp[idx][amount] != -1)return dp[idx][amount];

        if(coins[idx] <= amount)
        {
            int pick = f(coins,amount-coins[idx],idx,dp);
            int dontPick = f(coins,amount,idx-1,dp);

            return dp[idx][amount] = pick + dontPick;
        }

        return dp[idx][amount] = f(coins,amount,idx-1,dp);
    }

    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins,amount,coins.size()-1,dp);
    }
};