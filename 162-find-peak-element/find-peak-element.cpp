class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size() == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums.back() > nums[nums.size()-2])return nums.size()-1;

        int lo = 1;
        int hi = nums.size() - 2;

        while(lo <= hi)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }

            if(nums[mid] > nums[mid-1])
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }

        return lo;    
    }
};