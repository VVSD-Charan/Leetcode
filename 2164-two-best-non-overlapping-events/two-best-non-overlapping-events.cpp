class Solution {

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sorting events based on start times
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] < b[0])return true;
            if(a[0] > b[0])return false;
            return a[2] > b[2];
        });

        // Creating a suffix array to store suffix maxes
        int n = events.size();
        vector<int>suffix(n);
        suffix[n-1] = events[n-1][2];
        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = max(suffix[i+1],events[i][2]);
        } 

        // Binary search
        auto search_array = [](vector<vector<int>>&events,int target,int low,int high){
            while(high - low > 1){
                int mid = (low + high)>>1;
                if(events[mid][0] >= target){
                    high = mid;
                }else{
                    low = mid;
                }
            }

            if(events[low][0] >= target)return low;
            if(events[high][0] >= target)return high;
            return -1;
        };

        // Finding the max value of an interval that starts after each end time
        int max_answer = suffix[0];
        for(int i = 0 ; i < n-1 ; i++){
            int next_index = search_array(events,events[i][1]+1,i+1,n-1);
            if(next_index != -1){
                max_answer = max(max_answer,events[i][2] + suffix[next_index]);
            }
        }
        return max_answer;
    }
};