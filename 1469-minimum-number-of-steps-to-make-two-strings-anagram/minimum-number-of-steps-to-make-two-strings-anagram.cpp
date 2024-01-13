class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int>a(26,0);
        vector<int>b(26,0);

        for(int i = 0 ; i < s.length() ; i++)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }    

        int operations = 0;

        for(int i = 0 ; i < 26 ; i++)
        {
            if(a[i] > b[i])
            {
                operations += (a[i] - b[i]);
            }
        }

        return operations;
    }
};