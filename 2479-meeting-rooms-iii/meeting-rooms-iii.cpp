class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<long long>meets(n,0);
        vector<long long>timeEnds(n,0);

        sort(meetings.begin(),meetings.end());

        for(int i = 0 ; i < meetings.size() ; i++)
        {
            int min_index = 0;
            bool allocated = false;

            for(int j = 0 ; j < n ; j++)
            {
                if(meetings[i][0] >= timeEnds[j])
                {
                    meets[j]++;
                    timeEnds[j] = meetings[i][1];
                    allocated = true;
                    break;
                }
                else if(timeEnds[j] < timeEnds[min_index])
                {
                    min_index = j;
                }
            }

            if(!allocated)
            {
                meets[min_index]++;
                timeEnds[min_index] += (long long)((long long)meetings[i][1] - (long long)meetings[i][0]);
            }
        }

        long long max_meets = meets[0];
        int ans = 0;

        for(int i = 1 ; i < n ; i++)
        {
            if(meets[i] > max_meets)
            {
                max_meets = meets[i];
                ans = i;
            }
        }    

        return ans;
    }
};