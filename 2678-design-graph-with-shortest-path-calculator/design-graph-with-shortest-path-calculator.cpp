class Graph {
    vector<vector<pair<int,int>>>adj;

    int dijkstra(int src,int dest,vector<vector<pair<int,int>>>&adj)
    {
        vector<int>distance(adj.size(),1e9);
        distance[src] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});

        while(pq.size() > 0)
        {
            int node = pq.top().second;
            int dist = pq.top().first;  pq.pop();

            for(auto it : adj[node])
            {
                if(distance[it.first] > dist + it.second)
                {
                    distance[it.first] = dist + it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }

        return distance[dest];
    }

public:
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);

        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) 
    {
        int shortest = dijkstra(node1,node2,adj);    

        return (shortest < 1e9 ? shortest : -1);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */