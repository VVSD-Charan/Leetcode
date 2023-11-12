class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long long ans = 0;

        int l = max(0,n-2*limit);
        int r = min(limit,n);

        for(int i = l ; i <= r ; i++)
        {
            int min_l = max(0,n-i-limit);
            int max_l = min(limit,n-i);

            ans += (max_l-min_l+1);
        }    

        return ans;
    }
};