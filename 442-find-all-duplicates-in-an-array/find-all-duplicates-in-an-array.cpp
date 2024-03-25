class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int end_point = nums.size() + 1;
        vector<int>arr;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            int index = nums[i];

            if(index >= end_point){
                index = index - end_point;
            }

            if(nums[index-1] >= end_point)
            {
                arr.push_back(index);
            }
            else
            {
                nums[index-1] += end_point;
            }
        }

        return arr;
    }
};