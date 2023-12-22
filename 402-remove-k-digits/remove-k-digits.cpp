class Solution {

    string removeLeading(string &s)
    {
        string str = "";
        int idx = 0;

        while(idx < s.length() && s[idx] == '0')
        {
            idx++;
        }
        
        for(int i = idx ; i < s.length() ; i++)
        {
            str.push_back(s[i]);
        }

        if(str.size() == 0)return "0";
        return str;
    }

public:
    string removeKdigits(string num, int k) 
    {
        stack<char>st;

        for(int i = 0 ; i < num.length() ; i++)
        {
            while(st.size()>0 && k>0 && st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }    

        while(st.size()>0 && k>0)
        {
            st.pop();
            k--;
        }

        if(st.size() == 0)return "0";

        string res(st.size(),'0');
        int idx = st.size()-1;

        while(st.size()>0)
        {
            res[idx--]=st.top();
            st.pop();
        }

        return removeLeading(res);
    }
};