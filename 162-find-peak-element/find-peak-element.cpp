class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==1 || nums[0] > nums[1])return 0;
        if(nums.back() > nums[nums.size()-2])return nums.size()-1;

        int lo = 1;
        int hi = nums.size()-2;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;

            if(nums[mid] > nums[mid-1])
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        if(nums[hi]>nums[hi-1] && nums[hi]>nums[hi+1])return hi;
        return lo;    
    }
};