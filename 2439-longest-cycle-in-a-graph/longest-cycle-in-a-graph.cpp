class Solution {

    void dfs(vector<int>adj[],int src,vector<bool>&vis,stack<int>&st)
    {
        vis[src] = true;

        for(auto it : adj[src])
        {
            if(!vis[it])
            {
                dfs(adj,it,vis,st);
            }
        }

        st.push(src);
    }

    void dfsCycle(vector<int>adjT[],vector<int>&nodes,vector<bool>&vis,int src)
    {
        vis[src] = true;
        nodes.push_back(src);

        for(auto it : adjT[src])
        {
            if(!vis[it])
            {
                dfsCycle(adjT,nodes,vis,it);
            }
        }
    }

public:
    int longestCycle(vector<int>& edges) 
    {
        int n = edges.size();

        vector<int>adj[n];

        for(int i = 0 ; i < n ; i++)
        {
            if(edges[i] == -1)continue;

            adj[i].push_back(edges[i]);
        }    

        stack<int>st;

        vector<bool>vis(n,false);

        for(int i = 0 ; i < n ; i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis,st);
            }
        }

        vector<int>adjT[n];

        for(int i = 0 ; i < n ; i++)
        {
            for(auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            vis[i] = false;
        }

        int max_cycle = 0;

        while(st.size() > 0)
        {
            int node = st.top();    st.pop();

            if(vis[node])continue;

            vector<int>nodes;

            dfsCycle(adjT,nodes,vis,node);

            max_cycle = max(max_cycle ,(int)nodes.size());
        }

        return max_cycle > 1 ? max_cycle : -1;
    }
};