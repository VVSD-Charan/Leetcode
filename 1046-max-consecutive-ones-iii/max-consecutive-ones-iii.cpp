class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int lo = 0;
        int hi = 0;

        int ones = 0;
        int zeroes = 0;
        int max_length = 0;

        while(hi < nums.size())
        {
            if(nums[hi] == 1 || zeroes < k)
            {
                if(nums[hi] == 0)zeroes++;
                else ones++;

                max_length = max(max_length,hi-lo+1);
                hi++;
            }
            else
            {
                if(nums[lo] == 1)
                {
                    ones--;
                }
                else
                {
                    zeroes--;
                }
                lo++;
            }
        }

        return max_length;    
    }
};