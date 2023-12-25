class Solution {

    int atMost(vector<int>&arr,int target)
    {
        int lo = 0;
        int hi = 0;
        int curr_sum = 0;
        int total_arrays = 0;

        while(hi < arr.size())
        {
            curr_sum += arr[hi];

            while(lo < hi && curr_sum > target)
            {
                curr_sum -= arr[lo];
                lo++;
            }

            if(curr_sum <= target)
            {
                total_arrays += (hi-lo+1);
            }
            hi++;
        }

        return total_arrays;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return (atMost(nums,goal)-atMost(nums,goal-1));    
    }
};