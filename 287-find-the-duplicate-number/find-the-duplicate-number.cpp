class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        vector<int>arr(nums.size(),0);

        for(int i = 0 ; i < nums.size() ; i++)
        {
            arr[nums[i]-1]++;

            if(arr[nums[i]-1] > 1)return nums[i];
        }

        return nums.size()-1;
    }
};