class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;

        for(char it : s)
        {
            if(it == '(' || it == '[' || it == '{')
            {
                st.push(it);
            }
            else
            {
                if(st.size()==0)return false;

                if( it == '}')
                {
                    if(st.top() == '{')st.pop();
                    else return false;
                }
                else if(it == ')')
                {
                    if(st.top()=='(')st.pop();
                    else return false;
                }
                else if(it == ']')
                {
                    if(st.top()=='[')st.pop();
                    else return false;
                }
            }
        }

        return (st.size() == 0);    
    }
};