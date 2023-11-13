class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>>mp;

        for(int i = 0 ; i < strs.size() ; i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            mp[temp].push_back(strs[i]);
        }

        vector<vector<string>>arr;

        for(auto it = mp.begin() ; it != mp.end() ; it++)
        {
            vector<string>curr;

            for(auto i : it->second)
            {
                curr.push_back(i);
            }

            arr.push_back(curr);
        }

        return arr;
    }
};