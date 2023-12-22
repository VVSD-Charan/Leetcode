class Solution {
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

            if(st.size() == 1 && st.top()=='0')st.pop();
        }    

        while(st.size()>0 && k>0)
        {
            st.pop();   k--;
        }

        string res = "";

        while(st.size()>0)
        {
            res += st.top();
            st.pop();
        }

        if(res.size() == 0)return "0";
        
        reverse(res.begin(),res.end());
        return res;
    }
};