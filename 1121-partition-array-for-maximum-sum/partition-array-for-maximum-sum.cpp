class Solution {

    int getMax(vector<int>&arr,int i,int j)
    {
        int maxi = arr[i];

        for(int index = i+1 ; index <= j ; index++)
        {
            maxi = max(maxi , arr[index]);
        }

        return maxi;
    }

    int f(vector<int>&arr,int k,int i,int n,vector<int>&dp)
    {
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];

        int max_possible = 0;

        for(int index = i ; index < min(i+k,n) ; index++)
        {
            int maxx = getMax(arr,i,index);
            int len = (index - i + 1);

            max_possible = max(max_possible,(len*maxx) + f(arr,k,index+1,n,dp));
        }

        return dp[i] = max_possible;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int>dp(n,-1);

        return f(arr,k,0,n,dp);    
    }
};