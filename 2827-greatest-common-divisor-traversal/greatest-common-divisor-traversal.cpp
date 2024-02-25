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

void getFactors(int n,vector<int>&arr)
{
    if((n % 2) == 0)
    {
        arr.push_back(2);

        while(n > 0 && ((n % 2) == 0))
        {
            n >>= 1;
        }
    }

    for(int i = 3 ; i <= sqrt(n) ; i += 2)
    {
        if((n % i) == 0)
        {
            arr.push_back(i);

            while(n > 0 && ((n % i) == 0))
            {
                n = (n / i);
            }
        }
    }

    if(n > 1)arr.push_back(n);
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)return true;

        map<int,vector<int>>mp;

        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 1)continue;
            vector<int>primes;
            getFactors(nums[i],primes);

            for(auto it : primes)
            {
                mp[it].push_back(i);
            }
        }

        Disjoint DS(n);

        for(auto it = mp.begin() ; it != mp.end() ; it++)
        {
            for(int i = 1 ; i < it->second.size() ; i++)
            {
                DS.Union(it->second[i-1],it->second[i]);
            }
        }   

        int single_parent = DS.findParent(0);

        for(int i = 1 ; i < n ; i++)
        {
            if(DS.findParent(i) != single_parent)
            {
                return false;
            }
        } 

        return true;
    }
};