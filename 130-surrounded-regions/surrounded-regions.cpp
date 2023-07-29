class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='*';
                q.push({i,0});
            }
            if(board[i][m-1]=='O')
            {
                board[i][m-1]='*';
                q.push({i,m-1});
            }
        }

        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                board[0][i]='*';
                q.push({0,i});
            }
            if(board[n-1][i]=='O')
            {
                board[n-1][i]='*';
                q.push({n-1,i});
            }
        }

        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};

        while(q.size())
        {
            int x = q.front().first;
            int y = q.front().second;  q.pop();

            for(int i=0;i<4;i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx>=0 && cy>=0 && cx<n && cy<m && board[cx][cy]=='O')
                {
                    board[cx][cy]='*';
                    q.push({cx,cy});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='*')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};