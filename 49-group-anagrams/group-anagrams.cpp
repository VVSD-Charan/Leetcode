class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string,vector<string>>mp;

        for(auto it : strs)
        {
            string str = it;
            sort(str.begin(),str.end());

            mp[str].push_back(it);
        }

        vector<vector<string>>ans;

        for(auto it = mp.begin() ; it!=mp.end() ;it++)
        {
            ans.push_back(it->second);
        }    

        return ans;
    }
};