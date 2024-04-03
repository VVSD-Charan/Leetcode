class Solution {

    int dx[4] = {-1,+1,0,0};
    int dy[4] = {0,0,-1,+1};

    bool f(vector<vector<char>>&board,string &word,vector<vector<bool>>&visited,int i,int j,int k,int n,int m)
    {
        if(k == word.length())return true;

        bool ok = false;
        visited[i][j] = true;

        for(int x = 0 ; x < 4 ; x++)
        {
            int ci = i + dx[x];
            int cj = j + dy[x];

            if(ci < 0 || cj < 0 || ci >= n || cj >= m)continue;
            if(visited[ci][cj] || board[ci][cj] != word[k])continue;

            ok = (ok || f(board,word,visited,ci,cj,k+1,n,m));
        }

        visited[i][j] = false;
        return ok;
    }

public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        int k = word.length();

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(board[i][j] == word[0] && f(board,word,visited,i,j,1,n,m))
                {
                    return true;
                }
            }
        }    

        return false;
    }
};