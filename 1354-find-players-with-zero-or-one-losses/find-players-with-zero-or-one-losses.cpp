class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int>lost;
        map<int,int>wins;

        for(int i = 0 ; i < matches.size() ; i++)
        {
            wins[matches[i][0]]++;
            lost[matches[i][1]]++;
        }    

        vector<vector<int>>arr(2);

        for(auto it = wins.begin() ; it != wins.end() ; it++ )
        {
            if(lost.find(it->first) == lost.end())
            {
                arr[0].push_back(it->first);
            }
        }

        for(auto it = lost.begin() ; it != lost.end() ; it++)
        {
            if(it->second == 1)
            {
                arr[1].push_back(it->first);
            }
        }

        return arr;
    }
};