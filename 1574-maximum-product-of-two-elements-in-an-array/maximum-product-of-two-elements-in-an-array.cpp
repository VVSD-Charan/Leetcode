class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_element = max(nums[0],nums[1]);
        int second_max = min(nums[0],nums[1]);

        for(int i = 2 ; i < nums.size() ; i++)
        {
            if(nums[i] >= max_element)
            {
                second_max = max_element;
                max_element = nums[i];
            }
            else if(nums[i] >= second_max)
            {
                second_max = nums[i];
            }
        }    

        return (max_element-1)*(second_max-1);
    }
};