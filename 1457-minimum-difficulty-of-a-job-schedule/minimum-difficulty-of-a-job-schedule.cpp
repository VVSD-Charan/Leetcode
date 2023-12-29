class Solution {

    int f(vector<int>&arr,int idx,int d,vector<vector<int>>&dp)
    {
        if(idx == arr.size() && d == 0)return 0;
        if(idx == arr.size())return 1e8;
        if(d <= 0)return 1e8;
        if(dp[idx][d] != -1)return dp[idx][d];
        
        int curr_max = 0;
        int min_possible = 1e9;

        for(int i = idx ; i < arr.size() ; i++)
        {
            curr_max = max(curr_max,arr[i]);
            min_possible = min(min_possible,curr_max + f(arr,i+1,d-1,dp));
        }

        return dp[idx][d] = min_possible;
    }


public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        if(jobDifficulty.size() < d)return -1;

        vector<vector<int>>dp(jobDifficulty.size(),vector<int>(d+1,-1));
        return f(jobDifficulty,0,d,dp);    
    }
};