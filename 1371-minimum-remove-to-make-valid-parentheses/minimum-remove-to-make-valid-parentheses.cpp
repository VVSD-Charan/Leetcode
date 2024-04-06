class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int opened = 0;
        string temp = "";

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] != '(' && s[i] != ')')
            {
                temp += s[i];
            }
            else if(s[i] == '(')
            {
                opened = opened + 1;
                temp += s[i];
            }
            else if(opened > 0)
            {
                opened = opened - 1;
                temp += s[i];
            }
        }   

        string ans = "";
        for(int i = temp.length() - 1; i >= 0 ; i--)
        {
            if(temp[i] == '(' && opened > 0)
            {
                opened = opened - 1;
            }
            else
            {
                ans += temp[i];
            }
        } 

        reverse(ans.begin(),ans.end());
        return ans;
    }
};