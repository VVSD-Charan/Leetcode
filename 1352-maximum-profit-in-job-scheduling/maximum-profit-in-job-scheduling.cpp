class Solution {

    int solve(vector<vector<int>>&arr,vector<int>&startTime,int idx,vector<int>&dp)
    {
        if(idx >= arr.size())return 0;
        if(dp[idx] != -1)return dp[idx];

        int i = lower_bound(startTime.begin(),startTime.end(),arr[idx][1]) - startTime.begin();

        int pick = solve(arr,startTime,i,dp) + arr[idx][2];
        int dont_pick = solve(arr,startTime,idx+1,dp);

        return dp[idx] = max(pick,dont_pick);
    }
        
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>>arr;

        for(int i = 0 ; i < profit.size() ; i++)
        {
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(arr.begin(),arr.end());

        for(int i = 0 ; i < profit.size() ; i++)
        {
            startTime[i] = arr[i][0];
        }

        vector<int>dp(arr.size(),-1);

        return solve(arr,startTime,0,dp);
    }
};