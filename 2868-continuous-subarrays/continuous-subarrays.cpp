class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        long long low = 0;
        long long high = 0;
        long long total = 0;

        while(high < nums.size())
        {
            mp[nums[high]]++;

            auto mini = mp.begin();
            auto maxi = mp.end();   maxi--;

            while((*maxi).first - (*mini).first > 2)
            {
                mp[nums[low]]--;
                if(mp[nums[low]] == 0){
                    mp.erase(mp.find(nums[low]));
                }
                low = low + 1;

                mini = mp.begin();
                maxi = mp.end();    maxi--;
            }

            total += (high-low+1);
            high = high + 1;
        }

        return total;
    }
};