class Solution {

    bool openBrackets(char ch)
    {
        return (ch == '(' || ch == '[' || ch == '{');
    }

    bool matching(char c1,char c2)
    {
        return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}'));
    }

public:
    bool isValid(string s) 
    {
        if((s.length() % 2) == 1)return false;

        stack<char>st;

        for(char it : s)
        {
            if(openBrackets(it))
            {
                st.push(it);
            }
            else
            {
                if(st.size() == 0)return false;

                if(matching(st.top(),it))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return (st.size() == 0);    
    }
};