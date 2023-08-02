class Solution {
public:

    bool possible(vector<int>&arr,int div,int max_sum)
    {
        int sum = 0;

        for(auto it : arr)
        {
            sum += (it/div) + (it%div==0? 0:1);

            if(sum > max_sum)return false;
        }

        return (sum <= max_sum);
    }

    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int lo = 1;
        int hi = 1e9;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(possible(nums,mid,threshold))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(possible(nums,lo,threshold))return lo;
        return hi;    
    }
};