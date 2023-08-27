class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];

        vector<vector<int>>arr;

        for(int i = 1 ; i < intervals.size() ; i++)
        {
            if(intervals[i][0] <= r)
            {
                r = max(r , intervals[i][1]);
            }
            else
            {
                vector<int>temp;
                temp.push_back(l);
                temp.push_back(r);
                arr.push_back(temp);

                l = intervals[i][0];
                r = intervals[i][1];
            }
        }

        vector<int>temp;
        temp.push_back(l);
        temp.push_back(r);

        arr.push_back(temp);
        return arr;    
    }
};