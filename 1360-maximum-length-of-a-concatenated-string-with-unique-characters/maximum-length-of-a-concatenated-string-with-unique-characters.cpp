class Solution {

    int solve(vector<string>&arr,int i,unordered_map<char,int>&mp)
    {
        if(i < 0)return 0;

        int dont_pick = solve(arr,i-1,mp);

        set<char>s;
       
        for(char it : arr[i])
        {
            if(mp.find(it) != mp.end() || s.find(it) != s.end())
            {
                return dont_pick;
            }
            s.insert(it);
        }        

        for(auto it : s)
        {
            mp[it]++;
        }

        int pick = arr[i].length() + solve(arr,i-1,mp);

        for(auto it : s)
        {
            mp.erase(it);
        }

        return max(pick,dont_pick);
    }

public:
    int maxLength(vector<string>& arr) 
    {
        unordered_map<char,int>mp;
        return solve(arr,arr.size()-1,mp);
    }
};