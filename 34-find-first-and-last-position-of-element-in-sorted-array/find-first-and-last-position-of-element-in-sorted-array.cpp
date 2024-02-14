class Solution {

    int searchLeft(vector<int>&arr,int target,int n)
    {
        int lo = 0;
        int hi = n-1;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(arr[mid] >= target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(lo >= 0 && lo < n && arr[lo] == target)return lo;
        if(hi >= 0 && hi < n && arr[hi] == target)return hi;
        return -1;
    }

    int searchRight(vector<int>&arr,int target,int n)
    {
        int lo = 0;
        int hi = n-1;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(arr[mid] > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        if(hi >= 0 && hi < n && arr[hi] == target)return hi;
        if(lo >= 0 && lo < n && arr[lo] == target)return lo;
        return -1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>arr;
        int n = nums.size();

        int f_index = searchLeft(nums,target,n);
        int l_index = -1;
        if(f_index >= 0)l_index = searchRight(nums,target,n);

        arr.push_back(f_index);
        arr.push_back(l_index);
        return arr;    
    }
};