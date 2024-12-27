class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = 0;
        int curr_max = values[0];

        for(int i = 1 ; i < values.size() ; i++)
        {
            max_score = max(max_score,values[i]+curr_max-1);
            curr_max = max(values[i],curr_max-1);
        }

        return max_score;
    }
};