class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                grid[i][0]=-1;
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                grid[i][m-1]=-1;
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                grid[0][i]=-1;
                q.push({0,i});
            }
            if(grid[n-1][i]==1)
            {
                grid[n-1][i]=-1;
                q.push({n-1,i});
            }
        }

        int dx[4] = {-1 , +1 ,0 , 0};
        int dy[4] = {0 , 0, -1, +1};

        while(q.size())
        {
            int x = q.front().first;
            int y = q.front().second;  q.pop();

            for(int i=0;i<4;i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx>=0 && cy>=0 && cx<n && cy<m && grid[cx][cy]==1)
                {
                    q.push({cx,cy});
                    grid[cx][cy]=-1;
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt += (grid[i][j]==1);
            }
        }

        return cnt;    
    }
};