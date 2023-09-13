class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        vector<vector<int>>arr;

        for(int i = 0 ; i < n - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])continue;
            if(nums[i] > 0)return arr;

            int lo = i + 1;
            int hi = n - 1;

            while(lo < hi)
            {
                int sum = nums[lo] + nums[hi] + nums[i];

                if(sum == 0)
                {
                    arr.push_back({nums[lo],nums[hi],nums[i]});
                    lo++;   hi--;

                    while(lo < hi && nums[lo] == nums[lo-1])lo++;
                    while(lo < hi && nums[hi] == nums[hi+1])hi--;
                }
                else if(sum > 0)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }

        return arr;    
    }
};