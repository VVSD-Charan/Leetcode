class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_length = 0;
        map<char,int>mp;

        int lo = 0;
        int hi = 0;

        while(lo < s.length() && hi < s.length())
        {
            if(mp.find(s[hi]) == mp.end())
            {
                mp[s[hi]] = hi;
                max_length = max(max_length,hi-lo+1);

                hi++;
            }
            else
            {
                lo = max(lo,mp[s[hi]]+1);
                mp[s[hi]] = hi;

                max_length = max(max_length,hi-lo+1);
                hi++;
            }
        }

        return max_length;    
    }
};