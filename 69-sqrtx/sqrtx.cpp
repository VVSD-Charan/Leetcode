class Solution {
public:
    int mySqrt(int x) 
    {
        int lo = 0;
        int hi = 46340;

        while(hi - lo > 1)
        {
            long long mid = (lo + hi)>>1;
            long long pro = (mid * mid);

            if(pro == x)return (int)mid;

            if(pro > x)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        long long pro = ((long long)hi)*((long long)hi);
        if(pro <= x)return hi;
        return lo;
    }
};