class Solution {

    bool satisfy(vector<int>&a1,vector<int>&a2)
    {
        for(int i = 0 ; i < 60 ; i++)
        {
            if(a2[i] > a1[i])return false;
        }

        return true;
    }

public:
    string minWindow(string s, string t) 
    {
        vector<int>s_freq(60,0);
        vector<int>t_freq(60,0);   

        for(int i = 0 ; i < t.length() ; i++)
        {
            t_freq[t[i]-'A']++;
        }

        int index = 0;
        int start = 0;
        string str = "";

        while(index < s.length())
        {
            s_freq[s[index]-'A']++;

            if(s_freq[s[index]-'A'] >= t_freq[s[index]-'A'] && satisfy(s_freq,t_freq))
            {
                while(start < s.length() && s_freq[s[start]-'A'] > t_freq[s[start]-'A'])
                {
                    s_freq[s[start]-'A']--;
                    start = start + 1;
                }

                if(str.length() == 0 || index - start + 1 < str.length())
                {
                    str = s.substr(start,index-start+1);
                }
            }

            index++;
        }

        return str;
    }
};