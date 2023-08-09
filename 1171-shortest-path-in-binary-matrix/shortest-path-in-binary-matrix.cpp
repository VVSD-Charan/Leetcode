class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;

        vector<vector<bool>>vis(n,vector<bool>(n,false));

        int dx[8] = {-1,-1,-1,+1,+1,+1,0,0};
        int dy[8] = {+1,-1,0,-1,+1,0,-1,+1};

        queue<pair<int,int>>q;
        q.push({0,0});

        int path_length = 0;

        while(q.size() > 0)
        {
            path_length++;
            int nodes = q.size();

            while(nodes--)
            {
                int x = q.front().first;
                int y = q.front().second;   q.pop();

                if(x == n-1 && y == n-1)return path_length;

                for(int i = 0 ; i < 8 ; i++)
                {
                    int cx = x + dx[i];
                    int cy = y + dy[i];

                    if(cx >=0 && cy >= 0 && cx < n && cy < n && vis[cx][cy] == false && grid[cx][cy] == 0)
                    {
                        vis[cx][cy] = true;
                        q.push({cx,cy});
                    }
                }
            }
        }

        return -1;    
    }
};