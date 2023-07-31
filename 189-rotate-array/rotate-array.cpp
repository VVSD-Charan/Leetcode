class Solution {
public:

    void reverseArray(vector<int>&nums,int lo,int hi)
    {
        while(lo<hi)
        {
            swap(nums[lo],nums[hi]);
            lo++;   hi--;
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        k = (k%nums.size());
        if(k==0)return;

        int pivot = nums.size()-k;

        reverseArray(nums,pivot,nums.size()-1);
        reverseArray(nums,0,pivot-1);
        reverseArray(nums,0,nums.size()-1);    
    }
};