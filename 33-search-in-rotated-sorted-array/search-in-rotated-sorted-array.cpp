class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int lo = 0;
        int hi = nums.size()-1;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid]==target)return mid;
            if(nums[lo]==target)return lo;
            if(nums[hi]==target)return hi;

            if(nums[mid] < nums[lo])
            {
                if(nums[mid]<target && target<nums[hi])
                {
                    lo = mid;
                }
                else
                {
                    hi = mid;
                }
            }
            else
            {
                if(nums[lo]<target && target<nums[mid])
                {
                    hi = mid;
                }
                else
                {
                    lo = mid;
                }
            }
        }

        if(nums[lo]==target)return lo;
        if(nums[hi]==target)return hi;
        return -1;    
    }
};