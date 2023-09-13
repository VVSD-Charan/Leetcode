class DisjointSet
{
    vector<int>parent;
    vector<int>csize;

    public : 

    DisjointSet(int n)
    {
        parent.resize(n);
        csize.resize(n,1);

        for(int i = 0 ; i < n ; i++)parent[i] = i;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int>redundant(2);
        int n = edges.size();

        DisjointSet DS(n+1);

        for(auto it : edges)
        {
            if(DS.findParent(it[0]) == DS.findParent(it[1]))
            {
                redundant[0] = it[0];
                redundant[1] = it[1];
            }
            else
            {
                DS.Union(it[0],it[1]);
            }
        }

        return redundant;
    }
};