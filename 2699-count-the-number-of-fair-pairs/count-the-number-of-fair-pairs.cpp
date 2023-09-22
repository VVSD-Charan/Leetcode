class Solution {

    int searchLeft(vector<int>&nums,int lo,int hi,int target)
    {
        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] >= target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        
        if(nums[lo] >= target )return lo;
        if(nums[hi] >= target)return hi;

        return -1;
    }

    int searchRight(vector<int>&nums,int lo,int hi,int target)
    {
        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        
        if(nums[hi] <= target)return hi;
        if(nums[lo] <= target)return lo;

        return -1;
    }

public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        long long pairs = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            int l = searchLeft(nums,i+1,nums.size()-1,lower-nums[i]);
            int r = searchRight(nums,i+1,nums.size()-1,upper-nums[i]);

            if(l != -1 && r != -1)
            {
                pairs += (r - l + 1);
            }
        }

        return pairs;
    }
};