class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_product = INT_MIN;
        int curr_product = 1;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            curr_product = curr_product * nums[i];
            max_product = max(max_product, curr_product);

            if(curr_product == 0)curr_product = 1;
        }

        curr_product = 1;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            curr_product = curr_product * nums[i];
            max_product = max(max_product , curr_product);

            if(curr_product == 0)curr_product = 1;
        }

        return max_product;
    }
};