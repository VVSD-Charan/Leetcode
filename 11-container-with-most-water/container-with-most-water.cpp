class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max_area = 0;

        int lo = 0;
        int hi = height.size()-1;

        while(lo < hi)
        {
            int area = min(height[lo],height[hi])*(hi - lo);
            max_area = max(max_area , area);

            if(height[lo] < height[hi])
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }    

        return max_area;
    }
};