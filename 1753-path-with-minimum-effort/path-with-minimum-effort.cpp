class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};

        vector<vector<int>>distance(n,vector<int>(m,1e7));    
        distance[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});

        while(q.size() > 0)
        {
            auto it = q.top();   q.pop();
            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == m-1)return dist;

            for(int i = 0 ; i < 4 ; i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx >=0 && cy>=0 && cx < n && cy < m )
                {
                    int diff = max(dist , abs(heights[cx][cy] - heights[x][y]));

                    if(distance[cx][cy] > diff)
                    {
                        distance[cx][cy] = diff;
                        q.push({distance[cx][cy],{cx,cy}});
                    }
                }
            }
        }

        return distance[n-1][m-1];
    }
};