class Solution {

    int f(int n,vector<int>&dp)
    {
        if(n <= 3)return n;
        if(dp[n] != -1)return dp[n];

        int ans = INT_MAX;

        for(int i = 2 ; i <= sqrt(n) ; i++)
        {
            ans = min(ans , 1 + f(n-(i*i),dp) );
        }

        return dp[n] = ans;
    }

public:
    int numSquares(int n) 
    {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};