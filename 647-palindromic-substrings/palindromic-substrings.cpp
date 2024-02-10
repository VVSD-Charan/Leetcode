class Solution {
public:
    int countSubstrings(string s) 
    {
        int palindromes = 0;
        int n = s.length();

        //Odd length palindromes
        for(int i = 0 ; i < n ; i++)
        {
            int lo = i-1;
            int hi = i+1;

            //Single characters are palindromes too
            palindromes = palindromes + 1;

            while(lo >= 0 && hi < n && s[lo] == s[hi])
            {
                palindromes = palindromes + 1;
                lo = lo - 1;
                hi = hi + 1;
            }
        }

        //Even length palindromes
        for(int i = 1 ; i < n ; i++)
        {
            int lo = i-1;
            int hi = i;

            while(lo >= 0 && hi < n && s[lo] == s[hi])
            {
                palindromes = palindromes + 1;
                lo = lo - 1;
                hi = hi + 1;
            }
        }

        return palindromes;
    }
};