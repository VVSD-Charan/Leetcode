class Solution {

    bool possible(vector<int>&nums,vector<long long>&prefix,int n,int k)
    {
       long long lhs = (long long)((long long)nums[n-1]*(long long)n);
       long long rhs = prefix[n-1] + (long long)k;

       if(lhs <= rhs)return true;

       for(int i = n ; i < nums.size() ; i++)
       {
           lhs = (long long)((long long)nums[i]*(long long)n);
           rhs = (prefix[i]-prefix[i-n]) + (long long)k;

           if(lhs <= rhs)return true;
       }

       return false;
    }

public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        vector<long long>prefix(nums.size());
        prefix[0] = nums[0];

        for(int i = 1 ; i < nums.size() ; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }    

        int lo = 1;
        int hi = nums.size();

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

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