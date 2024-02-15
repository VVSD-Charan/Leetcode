class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int start_index = 0;
        int end_index = nums.size()-1;
        int index = 0;

        while(index <= end_index && start_index <= end_index)
        {
            if(nums[index] == 2)
            {
                swap(nums[index],nums[end_index]);
                end_index--;
            }
            else if(nums[index] == 0)
            {
                swap(nums[index],nums[start_index]);
                start_index++;

                if(start_index > index)index = start_index;
            }
            else
            {
                index++;
            }
        }    
    }
};