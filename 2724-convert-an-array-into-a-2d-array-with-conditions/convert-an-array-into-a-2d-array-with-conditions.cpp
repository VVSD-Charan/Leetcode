class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>>arr;

        set<int>s;
        map<int,int>mp;

        for(auto it : nums)
        {
            mp[it]++;
            s.insert(it);
        }    

        while(s.size() > 0)
        {
            int elements = s.size();
            vector<int>row;

            while(elements--)
            {
                int num = *(s.begin());  s.erase(s.begin());
                row.push_back(num);

                mp[num]--;
                if(mp[num] == 0)mp.erase(num);
            }

            arr.push_back(row);
            for(auto it = mp.begin() ; it != mp.end() ; it++)
            {
                s.insert(it->first);
            }
        }

        return arr;
    }
};