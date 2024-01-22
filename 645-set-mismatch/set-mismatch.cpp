class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        map<int,int>mp;
        vector<int>arr(2);

        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] == 2)
            {
                arr[0] = nums[i];
            }
        }    

        for(int i = 1 ; i <= nums.size() ; i++)
        {
            if(mp[i] == 0)
            {
                arr[1] = i;
                break;
            }
        }

        return arr;

    }
};