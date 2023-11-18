class Solution {

    bool possible(vector<int>&nums,vector<long>&prefix,long n,int k)
    {
        long lhs = (long)((long)nums[n-1]*n);
        long rhs = prefix[n-1] + k;

        if(lhs <= rhs)return true;

        for(int i = n ; i < nums.size() ; i++)
        {
            lhs = (long)((long)nums[i]*n);
            rhs = prefix[i] - prefix[i-n] + k;

            if(lhs <= rhs)return true;
        }

        return false;
    }

public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        vector<long>prefix(nums.size());
        prefix[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }    

        long lo = 1;
        long hi = nums.size();

        while(hi - lo > 1)
        {
            long mid = (lo + hi)>>1;

            if(possible(nums,prefix,mid,k))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        if(possible(nums,prefix,hi,k))return hi;
        return lo;
    }
};