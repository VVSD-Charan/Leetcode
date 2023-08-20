class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int l_max = 0;
        int r_max = 0;

        int lo = 0;
        int hi = arr.size()-1;

        int trapped = 0;

        while(lo <= hi)
        {
            if(arr[lo] < arr[hi])
            {
                if(arr[lo] > l_max)
                {
                    l_max = arr[lo];
                }
                else
                {
                    trapped += (l_max - arr[lo]);
                }
                lo++;
            }
            else
            {
                if(arr[hi] > r_max)
                {
                    r_max = arr[hi];
                }
                else
                {
                    trapped += (r_max - arr[hi]);
                }
                hi--;
            }
        }

        return trapped;    
    }
};