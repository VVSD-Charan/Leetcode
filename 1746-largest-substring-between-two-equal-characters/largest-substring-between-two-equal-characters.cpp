class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_length = -1;

        vector<int>arr(26,-1);

        int hi = 0;
        int n = s.length();

        while(hi < n)
        {
            if(arr[s[hi]-'a'] == -1)
            {
                arr[s[hi]-'a'] = hi;
                hi++;
            }
            else
            {
                int diff = hi - arr[s[hi]-'a'] - 1;

                max_length = max(max_length,diff);
                hi++;
            }
        }

        return max_length;
    }
};