class Solution {

    void reverseArray(vector<int>&nums,int i,int j)
    {
        while(i < j)
        {
            swap(nums[i],nums[j]);
            i = i + 1;
            j = j - 1;
        }
    }

public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(k >= n){
            k = (k % n);
        }
        if(k == 0)return;

        k = n - k;
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
        reverseArray(nums,0,n-1);
    }
};