class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        priority_queue<int>pq;

        for(auto it : points)
        {
            pq.push(it[0]);
        }    

        int max_width = 0;

        while(pq.size() > 1)
        {
            int num = pq.top();     pq.pop();
            int next_num = pq.top();

            max_width = max(max_width,num-next_num);
        }

        return max_width;
    }
};