class Solution {

    int getMax(vector<int>&arr,int i,int j)
    {
        int maxi = INT_MIN;

        for(int index = i ; index <= j ; index++)
        {
            maxi = max(maxi , arr[index]);
        }

        return maxi;
    }

    int f(vector<int>&arr,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(dp[i][j] != -1)return dp[i][j];

        if(j - i + 1 <= k)
        {
            int len = (j - i + 1);
            int maxi = getMax(arr,i,j);

            return dp[i][j] = (len * maxi);
        }

        int max_sum = INT_MIN;

        for(int index = i ; index < j ; index++)
        {
            int l = f(arr,i,index,k,dp);
            int r = f(arr,index+1,j,k,dp);

            max_sum = max(max_sum , l + r);
        }

        return dp[i][j] = max_sum;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(arr,0,n-1,k,dp);    
    }
};