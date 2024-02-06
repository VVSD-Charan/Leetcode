class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<string>>mp;

        for(int i = 0 ; i < strs.size() ; i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());

            mp[str].push_back(strs[i]);
        }    

        vector<vector<string>>arr;

        for(auto it : mp)
        {
            vector<string>temp;
            for(auto i : it.second)
            {
                temp.push_back(i);
            }
            arr.push_back(temp);
        }

        return arr;
    }
};