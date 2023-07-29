class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>minDistance(n,vector<int>(m,-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    minDistance[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};

        while(q.size())
        {
            auto it = q.front();   q.pop();
            int x = it.first;
            int y = it.second;

            for(int i=0;i<4;i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx>=0 && cy>=0 && cx<n && cy<m && minDistance[cx][cy]==-1)
                {
                    minDistance[cx][cy]=minDistance[x][y]+1;
                    q.push({cx,cy});
                }
            } 
        }

        return minDistance;    
    }
};