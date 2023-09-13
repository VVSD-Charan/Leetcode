class DisjointSet
{
    vector<int>parent;
    vector<int>csize;

    public:

    DisjointSet(int n)
    {
        parent.resize(n);
        csize.resize(n,1);

        for(int i = 0 ; i < n ; i++)parent[i]=i;
    }

    int findParent(int n)
    {
        if(parent[n] == n)return n;
        return parent[n] = findParent(parent[n]);
    }

    void Union(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)return;

        if(csize[pu] >= csize[pv])
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

        DisjointSet DS(n*m);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '1')
                {
                    if(i > 0 && grid[i-1][j] == '1')
                    {
                        DS.Union(i*m + j,(i-1)*m + j);
                    }
                    if(j > 0 && grid[i][j-1] == '1')
                    {
                        DS.Union(i*m + j,i*m + j - 1);
                    }
                }
            }
        }

        int islands = 0;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '1')
                {
                    int node = i*m + j;
                    islands += (DS.findParent(node) == node);
                }
            }
        }

        return islands;
    }
};