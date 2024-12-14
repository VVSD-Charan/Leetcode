class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long total = 0;
        multiset<int>ms;

        int low = 0;
        int high = 0;

        while(high < nums.size())
        {
           ms.insert(nums[high]);

           auto mini = ms.begin();
           auto maxi = ms.end();    maxi--;

           while(*maxi-*mini > 2)
           {
                ms.erase(ms.find(nums[low]));
                low++;

                maxi = ms.end();    maxi--;
                mini = ms.begin();
           }

           total += (high-low+1);
           high++;
        }

        return total;
    }
};