class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        map<int,vector<int>>index;

        //Maintain index map to store the indices at which stops are present
        for(int i = 0 ; i < routes.size() ; i++)
        {
            for(auto it : routes[i])
            {
                index[it].push_back(i);
            }
        }

        //It is un-necessary to visit same index multiple times so use visitedIndex array
        vector<bool>visitedIndex(routes.size(),false);
        queue<int>q;    q.push(source);

        int buses = 0;

        //Perform level order traversal on indices which are not visited
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

        //Since destination is not reachable return -1
        return -1;
    }
};