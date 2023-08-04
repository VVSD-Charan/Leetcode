class Solution {
public:

    bool dfs(vector<vector<char>>&board,string &word,int i,int j,int idx,vector<vector<bool>>&vis)
    {
        bool ans = false;
        
        if(idx == word.length()-1)return true;

        int dx[4] = {-1, +1, 0, 0};
        int dy[4] = {0, 0, -1, +1};

        for(int x = 0 ; x < 4 ; x++)
        {
            int cx = i + dx[x];
            int cy = j + dy[x];

            if(cx>=0 && cy>=0 && cx < board.size() && cy < board[0].size() && vis[cx][cy]==false && board[cx][cy]==word[idx+1])
            {
                vis[cx][cy] = true;
                ans = (ans | dfs(board, word, cx, cy, idx+1, vis));
                vis[cx][cy]=false;
            }
        }

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j]=true;
                    if(dfs(board,word,i,j,0,vis))
                    {
                        return true;
                    }
                    vis[i][j]=false;
                }
            }
        }

        return false;    
    }
};