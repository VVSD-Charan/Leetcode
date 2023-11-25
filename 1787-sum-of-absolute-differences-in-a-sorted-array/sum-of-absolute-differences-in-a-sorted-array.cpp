class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int sum = 0;
        int total_sum = 0;

        for(auto it : nums)
        {
            total_sum += it;
        }

        int till_now = 0;
        int rem = nums.size()-1;

        vector<int>arr;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            total_sum -= nums[i];

            int abs_sum = (nums[i]*till_now - sum) + (total_sum - nums[i]*rem);
            arr.push_back(abs_sum);

            sum += nums[i];
            till_now++;
            rem--;
        }    

        return arr;
    }
};