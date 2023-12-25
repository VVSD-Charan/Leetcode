class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<int>arr(26,0);

        int lo = 0;
        int hi = 0;
        int max_length = 0;

        while(hi < s.length())
        {
            arr[s[hi]-'A']++;

            while(hi-lo+1-*max_element(arr.begin(),arr.end()) > k)
            {
                arr[s[lo]-'A']--;
                lo++;
            }

            hi++;
            max_length = max(max_length,hi-lo);
        }

        return max_length;
    }
};