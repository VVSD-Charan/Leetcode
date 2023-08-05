class Solution {
public:

    bool f(string& s,set<string>&ss,int idx,int n,vector<int>&dp)
    {
        if(idx == n)return true;
        if(dp[idx]!=-1)return dp[idx];

        bool ans = false;
        string str = "";

        for(int i = idx ; i < n ; i++)
        {
            str.push_back(s[i]);

            if(ss.find(str) != ss.end())
            {
                ans = (ans | f(s,ss,i+1,n,dp));
            }
        }

        return dp[idx]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        set<string>ss(wordDict.begin(),wordDict.end());
        vector<int>dp(s.length(),-1);

        return f(s,ss,0,s.length(),dp);    
    }
};