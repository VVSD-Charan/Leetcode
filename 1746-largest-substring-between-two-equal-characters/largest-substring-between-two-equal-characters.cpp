class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        vector<int>min_index(26,-1);

        int ans = -1;

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(min_index[s[i]-'a'] == -1)
            {
                min_index[s[i]-'a'] = i;
            }
            else
            {
                ans = max(ans,i-min_index[s[i]-'a']-1);
            }
        }   

        return ans;
    }
};