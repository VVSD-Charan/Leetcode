class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);

        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int>q;
        int covered = 0;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);   covered++;
            }
        }

        while(q.size())
        {
            int node = q.front();  q.pop();

            for(auto it : adj[node])
            {
                indegree[it]--;;

                if(indegree[it]==0)
                {
                    q.push(it);   covered++;
                }
            }
        }

        return (covered==numCourses);
    }
};