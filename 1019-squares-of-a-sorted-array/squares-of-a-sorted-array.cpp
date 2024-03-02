class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
       int n = nums.size();

       for(int i = 0 ; i < n ; i++)
       {
           nums[i] = (nums[i] * nums[i]);
       }

       vector<int>arr(n);
       int index = n-1;
       int lo = 0;
       int hi = n-1;

       while(lo <= hi)
       {
           if(nums[lo] > nums[hi])
           {
               arr[index--] = nums[lo++];
           }
           else
           {
               arr[index--] = nums[hi--];
           }
       }

       return arr;
    }
};