class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.length() != t.length())return false;

        map<char,char>ss;
        map<char,char>tt;

        for(int i = 0 ; i < s.length() ; i++)
        {
            // If there is no mapping for both 
            if(ss.find(s[i]) == ss.end() && tt.find(t[i]) == tt.end())
            {
                ss[s[i]] = t[i];
                tt[t[i]] = s[i];
            }
            else if(ss.find(s[i]) == ss.end())
            {
                if(tt[t[i]] == s[i])
                {
                    ss[s[i]] = t[i];
                }
                else
                {
                    return false;
                }
            }
            else if(tt.find(t[i]) == tt.end())
            {
                if(ss[s[i]] == t[i])
                {
                    tt[t[i]] = s[i];
                }
                else
                {
                    return false;
                }
            }
            else if(ss[s[i]] != t[i] || tt[t[i]] != s[i])
            {
                return false;
            }
        }

        return true;
    }
};