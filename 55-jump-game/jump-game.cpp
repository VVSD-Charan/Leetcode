class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int max_reach = 0;
        int curr_reach = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            max_reach = max(max_reach,i+nums[i]);

            if(max_reach == i)
            {
                return false;
            }

            if(curr_reach == i)
            {
                curr_reach = max_reach;
            }
        }

        return true;
    }
};