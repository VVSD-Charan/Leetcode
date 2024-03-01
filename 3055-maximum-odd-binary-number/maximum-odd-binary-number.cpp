class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int count_ones = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            count_ones = count_ones + (s[i] - '0');
            s[i] = '0';
        }    

        count_ones = count_ones - 1;
        s.back() = '1';

        for(int i = 0 ; i < count_ones ; i++)
        {
            s[i] = '1';
        }
        return s;
    }
};