class Solution {
public:

    bool dfs(vector<vector<int>>&graph,vector<bool>&vis,vector<bool>&dfsvis,int src) {
        vis[src]=dfsvis[src]=true;
        for(auto it:graph[src]){
            if(!vis[it]){
                if(dfs(graph,vis,dfsvis,it)){
                    return true;
                }
            }else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[src]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<bool>dfsvis(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bool cycle=dfs(graph,vis,dfsvis,i);
            }
        }

        vector<int>safe;
        for(int i=0;i<n;i++)
        {
            if(!dfsvis[i])
            {
                safe.push_back(i);
            }
        }

        return safe;
    }
};