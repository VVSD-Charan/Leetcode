class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int lo = 0;
        int hi = nums.size()-1;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] < nums[hi])
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(nums[lo] > nums[hi])return nums[hi];
        return nums[lo];    
    }
};