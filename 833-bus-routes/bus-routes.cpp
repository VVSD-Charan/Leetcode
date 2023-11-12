class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        unordered_map<int,vector<int>>index;

        for(int i = 0 ; i < routes.size() ; i++)
        {
            for(auto it : routes[i])
            {
                index[it].push_back(i);
            }
        }

        set<int>visitedIndex;
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
                    if(visitedIndex.find(i) == visitedIndex.end())
                    {
                        visitedIndex.insert(i);

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