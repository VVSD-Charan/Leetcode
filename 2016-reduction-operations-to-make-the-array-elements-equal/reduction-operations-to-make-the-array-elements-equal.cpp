class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        int operations = 0;
        int to_add = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == nums[0])continue;

            if(nums[i] == nums[i-1])
            {
                operations += to_add;
            }
            else
            {
                to_add++;
                operations += to_add;
            }
        }   

        return operations;
    }
};