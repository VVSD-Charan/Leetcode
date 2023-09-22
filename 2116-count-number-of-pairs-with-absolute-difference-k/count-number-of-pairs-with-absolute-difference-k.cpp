class Solution {

    int searchLeft(vector<int>&nums,int lo,int hi,int target)
    {
        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] >= target)hi=mid;
            else lo = mid;
        }

        if(nums[lo] == target)return lo;
        if(nums[hi] == target)return hi;

        return -1;
    }

    int searchRight(vector<int>&nums,int lo,int hi,int target)
    {
        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(nums[mid] > target)hi=mid;
            else lo = mid;
        }

        if(nums[hi] == target)return hi;
        if(nums[lo] == target)return lo;

        return -1;
    }

public:
    int countKDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        int count_pairs = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            int target = k + nums[i];

            int l_index = searchLeft(nums,i+1,nums.size()-1,target);
            int r_index = searchRight(nums,i+1,nums.size()-1,target);

            if(l_index != -1 && r_index != -1)
            {
                count_pairs += (r_index - l_index + 1);
            }
        }

        return count_pairs;
    }
};