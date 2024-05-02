class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int max_pos = -1;
        map<int,int>mp;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(mp.find(-nums[i]) != mp.end())
            {
                max_pos = max(max_pos,abs(nums[i]));
            }
            mp[nums[i]]++;
        }

        return max_pos;
    }
};