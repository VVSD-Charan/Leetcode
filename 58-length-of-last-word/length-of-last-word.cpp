class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length()-1;

        while(n >= 0 && s[n] == ' ')
        {
            n = n - 1;
        }    

        int answer = 0;

        while(n >= 0 && s[n] != ' ')
        {
            answer = answer + 1;
            n = n - 1;
        }

        return answer;
    }
};