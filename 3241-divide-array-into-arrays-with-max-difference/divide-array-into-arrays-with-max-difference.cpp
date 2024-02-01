class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>>arr;

        for(int i = 0 ; i < nums.size() ; i = i + 3)
        {
            vector<int>temp;

            for(int j = i ; j < i + 3 ; j++)
            {
                temp.push_back(nums[j]);
            }

            arr.push_back(temp);
        }

        for(int i = 0 ; i < arr.size() ; i++)
        {
            int diff = arr[i][2] - arr[i][0];

            if(diff > k)return {};
        }

        return arr;    
    }
};