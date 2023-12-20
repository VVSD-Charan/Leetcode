class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();

        vector<int>prefix(n);
        vector<int>suffix(n);

        stack<int>pre;
        stack<int>next;

        for(int i = 0 ; i < n ; i++)
        {
            while(pre.size() > 0 && heights[pre.top()] >= heights[i])
            {
                pre.pop();
            }

            if(pre.size() == 0)
            {
                prefix[i] = i+1;
            }
            else
            {
                prefix[i] = i - pre.top();
            }
            pre.push(i);
        }

        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(next.size() > 0 && heights[next.top()] >= heights[i])
            {
                next.pop();
            }

            if(next.size() == 0)
            {
                suffix[i]  = n - i;
            }
            else
            {
                suffix[i] = next.top() - i;
            }

            next.push(i);
        }

        int max_area = 0;
        int idx = 0;

        for(int i = 0 ; i < n ; i++)
        {
            max_area = max(max_area , heights[i]*(prefix[i] + suffix[i] - 1));
        }
        return max_area;
    }
};