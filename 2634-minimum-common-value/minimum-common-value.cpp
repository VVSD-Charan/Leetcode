class Solution {

    bool search(vector<int>&arr,int target,int lo,int hi)
    {
        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(arr[mid] == target)return true;

            if(arr[mid] > target)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }

        return (arr[lo] == target || arr[hi] == target);
    }

public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0 ; i < n ; i++)
        {
            bool isPresent = search(nums2,nums1[i],0,m-1);

            if(isPresent)
            {
                return nums1[i];
            }
        }    

        return -1;
    }
};