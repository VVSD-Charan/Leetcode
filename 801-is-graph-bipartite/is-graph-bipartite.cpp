class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;

                queue<pair<int,int>>q;
                q.push({i,color[i]});

                while(q.size())
                {
                    int node = q.front().first;
                    int nodec = q.front().second;  q.pop();

                    for(auto it : graph[node])
                    {
                        if(color[it]==nodec)return false;
                        else if(color[it]==-1)
                        {
                            color[it]=1-nodec;
                            q.push({it,color[it]});
                        }
                    }
                }
            }
        }

        return true;    
    }
};