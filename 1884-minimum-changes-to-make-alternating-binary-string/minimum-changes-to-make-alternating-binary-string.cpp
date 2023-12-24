class Solution {
public:
    int minOperations(string s) 
    {
        int odd_ones = 0;
        int odd_zeroes = 0;
        int even_ones = 0;
        int even_zeroes = 0;
        int n = s.length();

        for(int i = 0 ; i < n ; i++)
        {
            if((i % 2) == 0)
            {
                if(s[i] == '1')
                {
                    even_ones++;
                }
                else
                {
                    even_zeroes++;
                }
            }
            else
            {
                if(s[i] == '1')
                {
                    odd_ones++;
                }
                else
                {
                    odd_zeroes++;
                }
            }
        }
        
        return n - max(even_ones+odd_zeroes,odd_ones+even_zeroes);
    }
};