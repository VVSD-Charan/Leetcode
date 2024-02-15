class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());

        int start_time = intervals[0][0];
        int end_time = intervals[0][1];  

        vector<vector<int>>merged;  

        for(int i = 1 ; i < intervals.size() ; i++)
        {
            if(intervals[i][0] <= end_time)
            {
                end_time = max(end_time,intervals[i][1]);
            }
            else
            {
                merged.push_back({start_time,end_time});
                start_time = intervals[i][0];
                end_time = intervals[i][1];
            }
        }

        merged.push_back({start_time,end_time});
        return merged;
    }
};