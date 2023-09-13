class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        set<vector<int>>s;
        int n = nums.size();

        for(int i = 0 ; i < (1 << n) ; i++)
        {
            vector<int>curr;

            for(int j = 0 ; j < n ; j++)
            {
                int res = ((1 << j) & i);

                if(res > 0)
                {
                    curr.push_back(nums[j]);
                }
            }

            s.insert(curr);
        }

        vector<vector<int>>ans;

        for(auto it : s)ans.push_back(it);
        return ans;    
    }
};