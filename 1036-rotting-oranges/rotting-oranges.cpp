class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int fresh_oranges = 0;
        queue<pair<int,int>>rotten;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    rotten.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh_oranges++;
                }
            }
        }

        int timer = 0;
        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};

        while(rotten.size() && fresh_oranges)
        {
            timer++;   
            int current_level = rotten.size();

            while(current_level--)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;   rotten.pop();

                for(int i=0;i<4;i++)
                {
                    int cx = x + dx[i];
                    int cy = y + dy[i];

                    if(cx>=0 && cy>=0 && cx<n && cy<m && grid[cx][cy]==1)
                    {
                        grid[cx][cy]=2;
                        fresh_oranges--;
                        rotten.push({cx,cy});
                    }
                }
            }
        }

        if(fresh_oranges>0)return -1;
        return timer;    
    }
};