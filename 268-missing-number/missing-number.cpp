class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int required_sum = (n*(n+1))/2;

        int current_sum = accumulate(nums.begin(),nums.end(),0);

        if(current_sum == required_sum)return 0;

        return required_sum - current_sum;
    }
};