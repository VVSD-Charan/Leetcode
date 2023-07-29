class DSU 
{
    public :

    vector<int>parent;
    vector<int>csize;

    DSU(int n)
    {
        parent.resize(n);
        csize.resize(n,1);

        for(int i=0;i<n;i++)parent[i]=i;
    }

    int findParent(int u)
    {
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u]);
    }

    void Union(int u,int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv)return;
        if(csize[pu]>csize[pv])
        {
            parent[pv]=pu;
            csize[pu]+=csize[pv];
        }
        else
        {
            parent[pu]=pv;
            csize[pv]+=csize[pu];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        DSU ds(n+1);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.Union(i,j);
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==i)cnt++;
        }

        return cnt;
    }
};