class Solution {

    int pairs;

    void mergeArrays(vector<int>&arr,int lo,int mid,int hi)
    {
       vector<int>temp;

       int i = lo;
       int j = mid + 1;

       while(i <= mid && j <= hi)
       {
           if(arr[i] > arr[j])
           {
               temp.push_back(arr[j++]);
           }
           else
           {
               temp.push_back(arr[i++]);
           }
       }

       while(i <= mid)temp.push_back(arr[i++]);
       while(j <= hi)temp.push_back(arr[j++]);

       for(int i = 0 ; i < temp.size() ; i++)
       {
           arr[i + lo] = temp[i];
       }
       temp.clear();
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