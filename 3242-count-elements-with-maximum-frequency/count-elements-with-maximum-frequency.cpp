class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        map<int,int>mp;

        int max_freq = 0;
        for(auto it : nums){
            max_freq = max(max_freq,++mp[it]);
        }    

        int elements = 0;
        for(auto it : mp){
            elements += (it.second == max_freq ? it.second : 0);
        }

        return elements;
    }
};