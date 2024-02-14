class Solution {
public:
    string longestPalindrome(string s) 
    {
        string res = "";
        int n = s.length();

        //Odd length substrings
        for(int i = 0 ; i < n ; i++)
        {
            int lo = i-1;
            int hi = i+1;

            string temp = "";

            while(lo >= 0 && hi < n && s[lo] == s[hi])
            {
                temp += s[lo];
                lo = lo - 1;
                hi = hi + 1;
            }

            int len = 2*temp.size() + 1;

            if(len > res.length())
            {
                string rev_temp = temp;
                reverse(rev_temp.begin(),rev_temp.end());

                res = rev_temp + s[i] + temp;
            }
        }    

        //Even length substrings
        for(int i = 0 ; i < n ; i++)
        {
            int lo = i-1;
            int hi = i;
            
            string temp = "";

            while(lo >= 0 && hi < n && s[lo] == s[hi])
            {
                temp += s[lo];
                lo = lo - 1;
                hi = hi + 1;
            }

            int len = 2*temp.length();

            if(len > res.length())
            {
                string rev_temp = temp;
                reverse(rev_temp.begin(),rev_temp.end());

                res = rev_temp + temp;
            }
        }

        return res;
    }
};