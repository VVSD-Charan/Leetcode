class Solution {

    char toLower(char ch)
    {
        if(ch >= 'a' && ch <= 'z')return ch;
        return (ch + 32);
    }

public:
    string makeGood(string s) 
    {
        stack<char>st;

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(st.size() == 0)
            {
                st.push(s[i]);
                continue;
            }

            char c1 = toLower(s[i]);
            char c2 = toLower(st.top());

            if(c1 == c2 && s[i] != st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string res = "";
        while(st.size())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};