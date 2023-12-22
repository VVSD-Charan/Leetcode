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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();

        DisjointSet DS(n);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    DS.Union(i,j);
                }
            }
        }

        int components = 0;

        for(int i = 0 ; i < n ; i++)
        {
            components += (DS.findParent(i) == i);
        }    

        return components;
    }
};