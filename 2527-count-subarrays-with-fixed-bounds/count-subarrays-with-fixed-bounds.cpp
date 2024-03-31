class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
       int pivot = -1;
       int maxi_index = -1;
       int mini_index = -1;

       long long arrays = 0;

       for(int i = 0 ; i < nums.size() ; i++)
       {
            if(nums[i] < minK || nums[i] > maxK)
            {
                pivot = i;
            }

            if(nums[i] == minK)mini_index = i;
            if(nums[i] == maxK)maxi_index = i;

            arrays = arrays + max(0,min(maxi_index,mini_index)-pivot);
       }

       return arrays;
    }
};