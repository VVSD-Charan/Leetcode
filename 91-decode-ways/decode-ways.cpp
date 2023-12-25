class Solution {

    int f(string &s,int idx,int sum,vector<vector<int>>&dp)
    {
        if(idx == s.length())return (sum == 0);
        if(dp[idx][sum] != -1)return dp[idx][sum];

        if(s[idx] == '0')
        {
            sum = sum*10;
            if(sum >=1 && sum <= 20)
            {
                return dp[idx][sum] = f(s,idx+1,0,dp);
            }
            return 0;
        }

        if(sum > 0)
        {
            sum = sum*10 + (s[idx]-'0');

            if(sum >= 1 && sum <= 26)
            {
                return dp[idx][sum] = f(s,idx+1,0,dp);
            }
            return 0;
        }

        int only_one = f(s,idx+1,0,dp);
        int next_too = f(s,idx+1,(s[idx]-'0'),dp);
        return dp[idx][sum] = only_one + next_too;
    }

public:
    int numDecodings(string s) 
    {
        vector<vector<int>>dp(s.length()+1,vector<int>(27,-1));
        return f(s,0,0,dp);    
    }
};