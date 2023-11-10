class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>>arr;

        queue<int>q;
        map<int,int>mp;

        for(auto it : nums)
        {
            mp[it]++;

            if(mp[it] == 1)q.push(it);
        }    

        while(q.size() > 0)
        {
            int elements = q.size();
            vector<int>row;

            while(elements--)
            {
                int num = q.front(); q.pop();
                row.push_back(num);

                mp[num]--;
                if(mp[num] == 0)mp.erase(num);
            }

            arr.push_back(row);
            for(auto it = mp.begin() ; it != mp.end() ; it++)
            {
                q.push(it->first);
            }
        }

        return arr;
    }
};