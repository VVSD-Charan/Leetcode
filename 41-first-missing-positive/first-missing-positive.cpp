class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] < 0)
            {
                nums[i] = 0;
            }
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
           int index = nums[i];
           if(index < 0){
            index*=-1;
           }

           if(index == 0 || index > nums.size())continue;
           if(nums[index-1] < 0)continue;

           if(nums[index-1] == 0)
           {
                nums[index-1] = index;
           }

           nums[index-1] *= -1;
        }

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] >= 0)return i+1;
        }

        return nums.size()+1;
    }
};