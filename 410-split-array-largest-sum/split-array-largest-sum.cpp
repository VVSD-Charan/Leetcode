class Solution {
public:

    bool possible(vector<int>&nums,int max_sum,int k)
    {
        int cnt = 1;
        int curr_sum = 0;

        for(int i=0;i<nums.size();i++)
        {
            curr_sum += nums[i];

            if(curr_sum > max_sum)
            {
                curr_sum = nums[i];
                cnt++;

                if(cnt > k)return false;
            }
        }

        return (cnt <= k);
    }

    int splitArray(vector<int>& nums, int k)
    {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = 1e9;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(possible(nums,mid,k))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(possible(nums,lo,k))return lo;
        return hi;    
    }
};