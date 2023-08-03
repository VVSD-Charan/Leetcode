class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);

        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        vector<int>order;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);  order.push_back(i);
            }
        }

        while(q.size())
        {
            int node = q.front();  q.pop();

            for(auto it : adj[node])
            {
                indegree[it]--;

                if(indegree[it]==0)
                {
                    q.push(it);   order.push_back(it);
                }
            }
        }

        if(order.size()==numCourses)return order;
        return {};    
    }
};