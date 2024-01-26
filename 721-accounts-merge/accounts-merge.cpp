class Disjoint
{
    vector<int>csize;
    vector<int>parent;
    
    public:
    
    Disjoint(int n)
    {
        csize.resize(n,1);
        parent.resize(n);
        
        for(int i = 0 ; i < n ; i++)parent[i] = i;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();

        Disjoint DS(n);
        map<string,int>mp;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < accounts[i].size() ; j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    DS.Union(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<set<string>>temp(n);

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1 ; j < accounts[i].size() ; j++)
            {
                temp[DS.findParent(i)].insert(accounts[i][j]);
            }
        }

        vector<vector<string>>ans;

        for(int i = 0 ; i < n ; i++)
        {
            if(temp[i].size() == 0)continue;

            vector<string>arr;
            arr.push_back(accounts[i][0]);

            for(auto it : temp[i])
            {
                arr.push_back(it);
            }

            ans.push_back(arr);
        }

        return ans;
    }
};