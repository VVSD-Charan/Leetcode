class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int>mp;
        stack<int>s;

        for(int i = nums2.size() - 1 ; i >= 0 ; i--)
        {
            while(s.size() > 0 && s.top() <= nums2[i])
            {
                s.pop();
            }

            if(s.size() == 0)mp[nums2[i]] = -1;
            else mp[nums2[i]] = s.top();

            s.push(nums2[i]);
        }

        vector<int>arr;

        for(auto it : nums1)
        {
            arr.push_back(mp[it]);
        }    

        return arr;
    }
};