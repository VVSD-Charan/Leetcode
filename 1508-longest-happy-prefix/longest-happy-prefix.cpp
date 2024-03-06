class Solution {
public:
    string longestPrefix(string s) 
    {
        string res = s;
        vector<int>match(res.length());

        match[0] = 0;
        for(int i = 1 ; i < res.length() ; i++)
        {
            int j = match[i-1];

            while(j > 0 && res[i] != res[j])
            {
                j = match[j-1];
            }

            if(res[i] == res[j])j++;
            match[i] = j;
        }    

        if(match.back() == 0)return "";
        return s.substr(0,match.back());
    }
};