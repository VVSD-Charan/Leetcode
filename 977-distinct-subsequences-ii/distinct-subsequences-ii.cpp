class Solution {
public:
    int distinctSubseqII(string s) 
    {
        int n = s.length();

        vector<long long>dp(n+1);
        dp[0] = 1;

        int mod = 1e9+7;

        map<char,int>mp;

        for(int i = 1 ; i <= n ; i++)
        {
            dp[i] = ((2 * dp[i-1])%mod);

            if(mp.find(s[i-1]) != mp.end())
            {
                dp[i] = ((dp[i] - dp[mp[s[i-1]]-1] + mod)%mod);
            }

            mp[s[i-1]] = i;
        }    

        return (dp[n]-1 + mod)%mod;
    }
};