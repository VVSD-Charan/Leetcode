class Solution {

    bool isVowel(char ch)
    {
        //Convert uppercase to lowercase (just to simplify checking whether it is vowel or not)
        if(ch >= 'A' && ch <= 'Z')ch+=32;

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string sortVowels(string s) 
    {
        vector<char>v;

        // Storing all vowels in vector
        for(char it : s)
        {
            if(isVowel(it))
            {
                v.push_back(it);
            }
        }    

        // Sorting vowels
        sort(v.begin(),v.end());
        
        int idx = 0;

        // Placing vowels in sorted order 
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