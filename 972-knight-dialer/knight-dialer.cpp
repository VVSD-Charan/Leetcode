class Solution {

    int mod = 1e9+7;

    int dfs(vector<vector<int>>&paths,int src,int rem,vector<vector<int>>&dp)
    {
        if(rem == 0)return 1;
        if(dp[rem][src] != -1)return dp[rem][src];

        int sum = 0;

        for(auto it : paths[src])
        {
            sum = (sum + dfs(paths,it,rem-1,dp))%mod;
        }

        return dp[rem][src] = sum;
    }

public:
    int knightDialer(int n) 
    {
        vector<vector<int>>paths(10);
        paths[0]={4,6};
        paths[1]={6,8};
        paths[2]={7,9};
        paths[3]={4,8};
        paths[4]={3,9,0};
        paths[6]={1,7,0};
        paths[7]={2,6};
        paths[8]={1,3};
        paths[9]={2,4};

        int ans = 0;
        vector<vector<int>>dp(n,vector<int>(10,-1));

        for(int i = 0 ; i < 10 ; i++)
        {
            ans = (ans + dfs(paths,i,n-1,dp))%mod;
        }

        return ans;
    }
};