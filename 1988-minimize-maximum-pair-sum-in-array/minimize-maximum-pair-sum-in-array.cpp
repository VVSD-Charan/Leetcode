class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        int max_sum = 0;
        int lo = 0;
        int hi = nums.size()-1;

        while(lo < hi)
        {
            max_sum = max(max_sum,nums[lo]+nums[hi]);
            lo++;   hi--;
        }    

        return max_sum;
    }
};