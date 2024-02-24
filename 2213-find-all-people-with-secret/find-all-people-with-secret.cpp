class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        vector<pair<int,int>>adj[n];

        for(auto it : meetings)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }    

        vector<int>times(n,1e9);
        times[0] = times[firstPerson] = 0;

        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({firstPerson,0});

        while(q.size() > 0)
        {
            int node = q.front().first;
            int timeKnown = q.front().second;   q.pop();

            for(auto it : adj[node])
            {
                if(timeKnown <= it.second && times[it.first] > timeKnown)
                {
                    times[it.first] = it.second;
                    q.push({it.first,times[it.first]});
                }
            }
        }

        vector<int>knows;

        for(int i = 0 ; i < n ; i++)
        {
            if(times[i] != 1e9)
            {
                knows.push_back(i);
            }
        }

        return knows;
    }
};