class Disjoint
{
    vector<int>parent;
    vector<int>csize;

    public:

    Disjoint(int n)
    {
        csize.resize(n+1,1);
        parent.resize(n+1);

        for(int i = 0 ; i <= n ; i++)parent[i] = i;
    }

    int findParent(int n)
    {
        if(n == parent[n])return n;
        return parent[n] = findParent(parent[n]);
    }

    void Union(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)return;

        if(csize[pu] > csize[pv])
        {
            csize[pu] += csize[pv];
            parent[pv] = pu;
        }
        else
        {
            csize[pv] += csize[pu];
            parent[pu] = pv;
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        Disjoint DS(n*m);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '0')continue;

                if(i > 0 && grid[i-1][j] == '1')DS.Union(i*m+j,(i-1)*m+j);
                if(j > 0 && grid[i][j-1] == '1')DS.Union(i*m+j,i*m+j-1);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '0')continue;

                islands += (DS.findParent(i*m+j) == i*m + j);
            }
        }

        return islands;
    }
};