class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();

        vector<int>left_max(n);
        left_max[0] = height[0];

        for(int i = 1 ; i < n ; i++)
        {
            left_max[i] = max(left_max[i-1],height[i]);
        }    

        int right_max = height[n-1];
        int trapped_water = 0;

        for(int i = n-2 ; i >= 0 ; i--)
        {
            right_max = max(right_max,height[i]);

            trapped_water += (min(right_max,left_max[i])-height[i]);
        }

        return trapped_water;
    }
};