class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        map<int,vector<int>>index;

        for(int i = 0 ; i < routes.size() ; i++)
        {
            for(auto it : routes[i])
            {
                index[it].push_back(i);
            }
        }

        vector<bool>visitedIndex(routes.size(),false);
        queue<int>q;    q.push(source);

        int buses = 0;

        while(q.size())
        {
            int nodes = q.size();

            while(nodes--)
            {
                int node = q.front();   q.pop();
                
                if(node == target)return buses;

                for(auto i : index[node])
                {
                    if(!visitedIndex[i])
                    {
                        visitedIndex[i] = true;

                        for(auto it : routes[i])
                        {
                            q.push(it);
                        }
                    }
                }
            }

            buses++;
        }    

        return -1;
    }
};