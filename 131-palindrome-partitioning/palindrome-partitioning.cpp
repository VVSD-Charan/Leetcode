class Solution {
public:

    bool isPalindrome(string s)
    {
        int lo = 0;
        int hi = s.length()-1;

        while(lo < hi)
        {
            if(s[lo] != s[hi])
            {
                return false;
            }
            lo++;   hi--;
        }

        return true;
    }

    void f(string s,vector<vector<string>>&ans,vector<string>&temp,int idx)
    {
        if(idx == s.length())
        {
            ans.push_back(temp);
            return;
        }

        string str = "";

        for(int i = idx ; i < s.length() ; i++)
        {
            str.push_back(s[i]);
            if(isPalindrome(str))
            {
                temp.push_back(str);
                f(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>temp;
        f(s,ans,temp,0);
        return ans;    
    }
};