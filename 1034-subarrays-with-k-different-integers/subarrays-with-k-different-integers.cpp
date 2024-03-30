class Solution {

    int atMost(vector<int>&arr,int k)
    {
        map<int,int>mp;
        int low = 0;
        int high = 0;
        int arrays = 0;

        while(high < arr.size())
        {
            mp[arr[high]]++;

            while(mp.size() > k)
            {
                mp[arr[low]]--;

                if(mp[arr[low]] == 0)
                {
                    mp.erase(arr[low]);
                }

                low = low + 1;
            }

            arrays += (high - low + 1);
            high = high + 1;
        }

        return arrays;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return (atMost(nums,k) - atMost(nums,k-1));    
    }
};