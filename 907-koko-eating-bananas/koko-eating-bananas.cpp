class Solution {
public:

    bool possible(vector<int>&piles,int n,int h)
    {
        int sum = 0;

        for(int i=0;i<piles.size();i++)
        {
            sum += (piles[i]/n);

            if(piles[i]%n > 0)sum++;

            if(sum > h)return false;
        }

        return (sum <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int lo = 1;
        int hi = 1e9;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(possible(piles,mid,h))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(possible(piles,lo,h))return lo;
        return hi;    
    }
};