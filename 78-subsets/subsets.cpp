class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>arr;
        int n = nums.size();

        for(int i = 0 ; i < (1 << n) ; i++)
        {
            vector<int>v;

            for(int j=0 ; j < n ; j++)
            {
                int res = ( i & (1<<j));

                if(res > 0)
                {
                    v.push_back(nums[j]);
                }
            }

            arr.push_back(v);
        }

        return arr;    
    }
};