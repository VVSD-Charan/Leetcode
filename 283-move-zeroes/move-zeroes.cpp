class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int swaps = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                swaps++;
            }
            else
            {
                nums[i-swaps]=nums[i];
            }
        }

        int hi = nums.size()-1;

        while(swaps--)
        {
            nums[hi]=0;
            hi--;
        }    
    }
};