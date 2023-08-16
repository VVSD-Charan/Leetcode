class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>>adj[n];

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }    

        vector<int>distance(n,1e8);

        distance[src] = 0;
        
        queue<pair<int,int>>q;
        q.push({src,0});

        while(q.size()>0 && k > -1)
        {
            int nodes = q.size();

            while(nodes--)
            {
                auto i = q.front();    q.pop();
                int node = i.first;
                int dist = i.second;

                for(auto it : adj[node])
                {
                    if(distance[it.first] > dist + it.second)
                    {
                        distance[it.first] = dist + it.second;
                        q.push({it.first,distance[it.first]});
                    }
                }
            }
            k--;
        }

        return distance[dst]>=1e8? -1 : distance[dst];
    }
};