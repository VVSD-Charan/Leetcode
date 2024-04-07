class Solution {
public:
    bool checkValidString(string s) 
    {
        int mini = 0;
        int maxi = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            mini += (s[i] == '(') ? 1 : -1;
            maxi += (s[i] != ')') ? 1 : -1;

            if(maxi < 0)return false;
            mini = max(mini,(int)0);
        }  

        return (mini == 0);
    }
};