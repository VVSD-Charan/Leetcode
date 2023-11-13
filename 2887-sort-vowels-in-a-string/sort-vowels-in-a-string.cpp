class Solution {

    bool isVowel(char ch)
    {
        if(ch >= 'A' && ch <= 'Z')ch+=32;

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string sortVowels(string s) 
    {
        vector<char>v;

        for(char it : s)
        {
            if(isVowel(it))
            {
                v.push_back(it);
            }
        }    

        sort(v.begin(),v.end());
        
        int idx = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = v[idx++];
            }
        }

        return s;
    }
};