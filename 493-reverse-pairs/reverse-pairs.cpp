class Solution {

    int pairs;

    void mergeArrays(vector<int>&arr,int lo,int mid,int hi)
    {
       int *a = new int[hi - lo + 1];

       int i = lo;
       int j = mid + 1;
       int idx = 0;

       while(i <= mid && j <= hi)
       {
           if(arr[i] > arr[j])
           {
               a[idx++] = arr[j++];
           }
           else
           {
               a[idx++] = arr[i++];
           }
       }

       while(i <= mid)a[idx++] = arr[i++];
       while(j <= hi)a[idx++] = arr[j++];

       for(int i = 0 ; i < hi - lo + 1 ; i++)
       {
           arr[i + lo] = a[i];
       }

       delete []a;
    }

    void compare(vector<int>&arr,int lo,int mid,int hi)
    {
        int curr = mid + 1;

        for(int i = lo ; i <= mid ; i++)
        {
            while(curr <= hi && arr[i] > (long long)2*arr[curr])
            {
                curr++;
            }

            pairs += (curr - mid - 1);
        }
    }

    void mergeSort(vector<int>&arr,int lo,int hi)
    {
        if(lo >= hi)return;

        int mid = (lo + hi)>>1;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);

        compare(arr,lo,mid,hi);
        mergeArrays(arr,lo,mid,hi);
    }

public:
    int reversePairs(vector<int>& nums) 
    {
        pairs = 0;  

        mergeSort(nums,0,nums.size()-1);

        return pairs;  
    }
};