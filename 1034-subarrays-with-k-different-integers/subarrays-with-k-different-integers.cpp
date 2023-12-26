class Solution {

    int atMost(vector<int>&arr,int k,int n)
    {
        unordered_map<int,int>mp;

        int total_arrays = 0;
        int lo = 0;
        int hi = 0;

        while(hi < n)
        {
            mp[arr[hi]]++;

            while(mp.size() > k)
            {
                mp[arr[lo]]--;

                if(mp[arr[lo]] == 0)
                {
                    mp.erase(arr[lo]);
                }

                lo = lo + 1;
            }

            total_arrays = total_arrays + (hi - lo + 1);
            hi = hi + 1;
        }

        return total_arrays;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int n = nums.size();
        return (atMost(nums,k,n) - atMost(nums,k-1,n));    
    }
};