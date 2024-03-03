class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        if(arr[0] > arr[1])return 0;
        if(arr[arr.size()-1] > arr[arr.size()-2])return arr.size()-1;

        int lo = 1;
        int hi = arr.size()-2;

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(arr[mid] > arr[mid-1])
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        if(arr[lo] > arr[lo+1] && arr[lo] > arr[lo-1])return lo;
        return hi;    
    }
};