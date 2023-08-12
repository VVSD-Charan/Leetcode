class Solution {
public:

    vector<int> permutate(vector<int>&nums)
    {
        int ind = -1;

        for(int i = nums.size()-2 ; i >= 0 ; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i;
                break;
            }
        }

        if(ind == -1)
        {
            reverse(nums.begin(),nums.end());
            return nums;
        }
        
        for(int i = nums.size()-1 ; i > ind ; i--)
        {
            if(nums[i] > nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        reverse(nums.begin()+ind+1,nums.end());
        return nums;
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        int possible = n;

        for(int i = n-1 ; i > 1 ; i--)
        {
            possible *= i;
        }

        vector<vector<int>>arr;

        while(possible--)
        {
            arr.push_back(permutate(nums));
        }

        return arr;
    }
};