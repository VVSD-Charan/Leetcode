class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int required_sum = (n*(n+1))/2;

        for(auto it : nums)
        {
            required_sum -= it;
        }

        return required_sum;
    }
};