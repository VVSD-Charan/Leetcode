class Solution {
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        map<int,int>mp;

        for(int i = 0 ; i < nums2.size() ; i++)
        {
            mp[nums2[i]]++;
        }

        vector<int>arr;
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            if(i > 0 && nums1[i] == nums1[i-1])continue;

            if(mp.find(nums1[i]) != mp.end())arr.push_back(nums1[i]);
        }

        return arr;
    }
};