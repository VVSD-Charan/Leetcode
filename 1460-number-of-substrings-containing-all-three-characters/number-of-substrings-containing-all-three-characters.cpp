class Solution {

    int atMost(string &s,int k)
    {
        int total_strings = 0;
        int lo = 0;
        int hi = 0;

        unordered_map<char,int>mp;

        while(hi < s.length())
        {
            mp[s[hi]]++;

            while(mp.size() > k)
            {
                mp[s[lo]]--;

                if(mp[s[lo]] == 0)
                {
                    mp.erase(s[lo]);
                }

                lo = lo + 1;
            }

            total_strings = total_strings + (hi - lo + 1);
            hi = hi + 1;
        }

        return total_strings;
    }

public:
    int numberOfSubstrings(string s) 
    {
        return (atMost(s,3) - atMost(s,2));    
    }
};