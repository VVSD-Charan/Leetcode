class Solution {

    bool valid(vector<int>&arr)
    {
        if(arr.size() <= 1)return true;

        int diff = arr[1]-arr[0];

        for(int i = 2 ; i < arr.size() ; i++)
        {
            if(arr[i]-arr[i-1] != diff)
            {
                return false;
            }
        }

        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool>ans;
        vector<pair<int,int>>vp;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            vp.push_back({nums[i],i});
        }    

        sort(vp.begin(),vp.end());

        for(int i = 0 ; i < l.size() ; i++)
        {
            vector<int>temp;

            for(auto it : vp)
            {
                if(it.second >= l[i] && it.second <= r[i])
                {
                    temp.push_back(it.first);
                }
            }

            ans.push_back(valid(temp));
        }

        return ans;
    }
};