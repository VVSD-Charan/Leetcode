class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maximum_step = 0;
        int curr_max = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            curr_max = max(curr_max,i + nums[i]);

            if(maximum_step == i)
            {
                if(curr_max <= i && curr_max < nums.size()-1)return false;

                maximum_step = curr_max;
            }
        }

        return true;
    }
};