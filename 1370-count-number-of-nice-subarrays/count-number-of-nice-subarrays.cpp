class Solution {

    int atMost(vector<int>&arr,int k)
    {
        int total_arrays = 0;
        int total_odd = 0;
        int lo = 0;
        int hi = 0;

        while(hi < arr.size())
        {
            total_odd += (arr[hi]%2);

            while(lo < hi && total_odd > k)
            {
                total_odd -= (arr[lo]%2);
                lo = lo + 1;
            }

            if(total_odd <= k)
            {
                total_arrays += (hi-lo+1);
            }
            hi = hi + 1;
        }

        return total_arrays;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return (atMost(nums,k)-atMost(nums,k-1));    
    }
};