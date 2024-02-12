class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //Boyer Moore algorithm
        int probable_candidate = -1;
        int counter = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(counter == 0)
            {
                probable_candidate = nums[i];
                counter = counter + 1;
            }
            else if(nums[i] == probable_candidate)
            {
                counter = counter + 1;
            }
            else
            {
                counter = counter - 1;
            }
        }

        return probable_candidate;
    }
};