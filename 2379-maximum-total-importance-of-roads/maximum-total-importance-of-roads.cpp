class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int>degree(n,0);

        for(auto it : roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
        }

        priority_queue<pair<int,int>>pq;

        for(int i = 0 ; i < n ; i++)
        {
            pq.push({degree[i],i});
        }

        int number = n;

        while(pq.size())
        {
            int node = pq.top().second; pq.pop();
            degree[node] = number--;
        }

        long long sum = 0;

        for(auto it : roads)
        {
            sum = sum + degree[it[0]] + degree[it[1]];
        }
        
        return sum;
    }
};