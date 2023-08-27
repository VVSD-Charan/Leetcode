class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length()-1;

        while(n >= 0 && s[n] == ' ')
        {
            n--;
        }    

        int cnt = 0;

        for(int i = n ; i >= 0 ; i--)
        {
            if(s[i] == ' ')return cnt;

            cnt++;
        }

        return cnt;
    }
};