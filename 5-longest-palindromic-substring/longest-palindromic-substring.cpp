class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.length()==1)return s;
        string longest_palindrome = s.substr(0,1);

        //Check for odd length substrings
        for(int i=1;i<s.length();i++)
        {
            string str = "";
            int lo = i-1;
            int hi = i+1;

            while(lo>=0 && hi<s.length())
            {
                if(s[hi]==s[lo])
                {
                    str.push_back(s[lo]);
                    lo--;   hi++;
                }
                else
                {
                    break;
                }
            }

            if(2*str.length()+1 > longest_palindrome.length())
            {
                string revstr = str;
                reverse(revstr.begin(),revstr.end());
                longest_palindrome = revstr + s.substr(i,1) + str; 
            }
        }

        //Check for even length palindromes
        for(int i=1 ;i<s.length();i++)
        {
            if(s[i]!=s[i-1])continue;

            string str = s.substr(i,1);
            int lo = i-2;
            int hi = i+1;

            while(lo>=0 && hi<s.length())
            {
                if(s[lo]==s[hi])
                {
                    str.push_back(s[lo]);
                    lo--;   hi++;
                }
                else
                {
                    break;
                }
            }

            if(2*str.length() > longest_palindrome.length())
            {
                string res = str;
                reverse(res.begin(),res.end());
                longest_palindrome = res + str;
            }
        }

        return longest_palindrome;
    }
};