class Solution {

    static bool cmp(vector<int>&a , vector<int>&b)
    {
        if(a[1] < b[1])return true;
        if(a[1] > b[1])return false;

        return a[0] > b[0];
    }

public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(),events.end(),cmp);

        int max_day = 0;

        for(auto it : events)
        {
            max_day = max(max_day,it[1]);
        }    

        set<int>s;

        for(int i = 1 ; i <= max_day ; i++)
        {
            s.insert(i);
        }

        int events_attended = 0;

        for(int i = 0 ; i < events.size() ; i++)
        {
            auto it = s.lower_bound(events[i][0]);

            if(it == s.end())continue;

            if(*it <= events[i][1])
            {
                events_attended++;
                s.erase(it);
            }
        }

        return events_attended;
    }
};