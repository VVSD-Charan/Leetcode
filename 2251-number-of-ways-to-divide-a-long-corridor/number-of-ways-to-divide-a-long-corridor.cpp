class Solution {

    int mod = 1e9+7;

    int f(string &s,int idx,int cnt,vector<vector<int>>&dp)
    {
        if(idx < 0)return (cnt == 2);
        if(dp[idx][cnt] != -1)return dp[idx][cnt];

        if(s[idx] == 'P')
        {
            if(cnt == 2)
            {
                int dontBreak = f(s,idx-1,cnt,dp);
                int breakHere = f(s,idx-1,0,dp);

                return dp[idx][cnt] = (dontBreak + breakHere)%mod;
            }
            return dp[idx][cnt] = (f(s,idx-1,cnt,dp)%mod);
        }

        if(s[idx] == 'S')
        {
            if(cnt == 2)
            {
                return dp[idx][cnt] = f(s,idx-1,1,dp);
            }
            return dp[idx][cnt] = f(s,idx-1,cnt+1,dp);
        }

        return dp[idx][cnt] = 0;
    }

public:
    int numberOfWays(string corridor) 
    {
        int count_seats = count(corridor.begin(),corridor.end(),'S');
        if(count_seats == 0 || (count_seats % 2) == 1)return 0;    

        vector<vector<int>>dp(corridor.length(),vector<int>(3,-1));
        return f(corridor,corridor.length()-1,0,dp);
    }
};