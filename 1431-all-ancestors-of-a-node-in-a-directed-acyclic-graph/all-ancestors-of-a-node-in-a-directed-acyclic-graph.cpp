class Solution {
    void solve(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = true;

        for(auto it: adj[node]){
            if(!vis[it]){
                solve(it, adj, vis);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>>res;

        for(int i = 0; i < n; i++){
            vector<int>temp;
            vector<int>vis(n, 0);
            solve(i, adj, vis);
            for(int node = 0; node < n; node++){
                if(node == i){
                    continue;
                }
                if(vis[node]){
                    temp.push_back(node);
                }
            }
            res.push_back(temp);
        }

        return res;        
    }
};