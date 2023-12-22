class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length();
        int ones = 0;

        for(int  i = 0 ; i < n ; i++)
        {
            ones += (s[i] == '1');
        }    

        int max_score = 0;
        int zeroes = 0;

        for(int i = 0 ; i < n-1 ;i++)
        {
            zeroes += (s[i] == '0');
            ones -= (s[i] == '1');

            max_score = max(max_score,zeroes+ones);
        }

        return max_score;
    }
};