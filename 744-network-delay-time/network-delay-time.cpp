class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>adj[n+1];

        for(auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>distance(n+1,1e8);
        distance[k] = 0;

        queue<pair<int,int>>q;
        q.push({0,k});

        while(q.size())
        {
            auto i = q.front();     q.pop();
            int dist = i.first;
            int node = i.second;

            for(auto it : adj[node])
            {
                if(distance[it.first] > it.second + dist)
                {
                    distance[it.first] = it.second + dist;
                    q.push({distance[it.first],it.first});
                }
            }
        }

        int max_time = 0;

        for(int i = 1 ; i <= n ; i++)
        {
            max_time = max(max_time , distance[i]);
        }

        return max_time>=1e8 ? -1 : max_time;
    }
};