class Solution {

    void mergeArrays(vector<pair<int,int>>&arr,int lo,int mid,int hi)
    {
        vector<pair<int,int>>temp(hi-lo+1);
        int i = lo;
        int j = mid + 1;
        int index = 0;

        while(i <= mid && j <= hi)
        {
            if(arr[i].first > arr[j].first)
            {
                temp[index] = arr[j];
                j = j + 1;
            }
            else
            {
                temp[index] = arr[i];
                i = i + 1;
            }
            index = index + 1;
        }

        while(i <= mid)
        {
            temp[index++] = arr[i++];
        }

        while(j <= hi)
        {
            temp[index++] = arr[j++];
        }

        for(i = lo ; i <= hi ; i++)
        {
            arr[i] = temp[i - lo];
        }
    }

    void countInversions(vector<pair<int,int>>&arr,int lo,int mid,int hi,int &counter)
    {
        int total_count = 0;
        int j = mid + 1;

        for(int i = lo ; i <= mid ; i++)
        {
            while(j <= hi && (long long)arr[i].first > (long long)2*(long long)arr[j].first)
            {
                total_count++;
                j = j + 1;
            }
            counter += total_count;
        }
    }

    void mergeSort(vector<pair<int,int>>&arr,int lo,int hi,int &counter)
    {
        if(lo >= hi)return;

        int mid = (lo + hi)>>1;

        mergeSort(arr,lo,mid,counter);
        mergeSort(arr,mid+1,hi,counter);

        countInversions(arr,lo,mid,hi,counter);
        mergeArrays(arr,lo,mid,hi);
    }

public:
    int reversePairs(vector<int>& nums) 
    {
        vector<pair<int,int>>arr;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            arr.push_back({nums[i],i});
        }   

        int ans = 0;
        mergeSort(arr,0,n-1,ans);
        return ans;
    }
};