class Solution {

    int f(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(j < 0)return 1;
        if(i < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        if(s[i] == t[j])
        {
            int pick = f(s,t,i-1,j-1,dp);
            int dontPick = f(s,t,i-1,j,dp);

            return dp[i][j] = pick + dontPick;
        }

        return dp[i][j] = f(s,t,i-1,j,dp);
    }

public:
    int numDistinct(string s, string t) 
    {
        vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
        return f(s,t,s.length()-1,t.length()-1,dp);    
    }
};