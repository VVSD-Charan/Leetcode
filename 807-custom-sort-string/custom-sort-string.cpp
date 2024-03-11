class Solution {
public:
    string customSortString(string order, string s) 
    {
        string res_string = "";

        int frequencies[26];
        memset(frequencies,0,sizeof frequencies);

        for(int i = 0 ; i < s.length() ; i++)
        {
            frequencies[s[i]-'a']++;
        }    

        for(int i = 0 ; i < order.length() ; i++)
        {
            while(frequencies[order[i]-'a'] > 0)
            {
                res_string += order[i];
                frequencies[order[i]-'a']--;
            }
        }

        for(int i = 0 ; i < 26 ; i++)
        {
            while(frequencies[i] > 0)
            {
                res_string += (i + 'a');
                frequencies[i]--;
            }
        }

        return res_string;
    }
};