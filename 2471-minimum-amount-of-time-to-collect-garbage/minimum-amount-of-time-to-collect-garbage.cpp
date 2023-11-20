class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        vector<int>prefixSum(travel.size()+1,0);

        for(int i = 1 ; i <= travel.size() ; i++)
        {
            prefixSum[i] = prefixSum[i-1] + travel[i-1];
        }    

        int total_picks = 0;
        int last_p = 0;
        int last_g = 0;
        int last_m = 0;

        for(int i = 0 ; i < garbage.size() ; i++)
        {
            total_picks += garbage[i].length();

            for(char it : garbage[i])
            {
                if(it == 'P')last_p=i;
                if(it == 'M')last_m=i;
                if(it == 'G')last_g=i;
            }
        }

        int total_travel = prefixSum[last_p]+prefixSum[last_g]+prefixSum[last_m];
        return total_picks+total_travel;
    }
};