class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        map<int,int>mp;

        for(auto it : nums)
        {
            mp[it]++;
        }    

        int operations = 0;

        for(auto it : mp)
        {
            int freq = it.second;

            if(freq == 1)return -1;

            if(freq == 2 || freq == 3)
            {
                operations++;
            }
            else
            {
                int div = (freq / 3);
                int diff = freq - 3*div;

                if(diff&1)
                {
                    diff = diff + 3;

                    operations += (div-1) + (diff/2);
                }
                else
                {
                    operations += div + (diff / 2);
                }
            }
        }

        return operations;
    }
};