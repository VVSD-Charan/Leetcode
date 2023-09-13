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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int redundant = 0;
        int components = 0;

        DisjointSet DS(n);

        for(auto it : connections)
        {
            if(DS.findParent(it[0]) == DS.findParent(it[1]))
            {
                redundant++;
            }
            else
            {
                DS.Union(it[0],it[1]);
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            components += (DS.findParent(i)==i);
        }

        if(components - 1 > redundant)return -1;

        return components - 1;
    }
};