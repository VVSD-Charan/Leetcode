class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        long long max_perimeter = -1;
        long long curr_sum = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(curr_sum > nums[i] && i >= 2)
            {
                max_perimeter = max(max_perimeter,curr_sum + nums[i]);
            }
            curr_sum = curr_sum + nums[i];
        }

        return max_perimeter;
    }
};