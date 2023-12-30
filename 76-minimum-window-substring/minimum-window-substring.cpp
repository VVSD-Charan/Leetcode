class Solution {

    bool satisfies(vector<int>&a,vector<int>&b)
    {
        for(int i = 0 ; i < 60 ; i++)
        {
            if(b[i] > a[i])
            {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t) 
    {
        vector<int>s_freq(60,0);
        vector<int>t_freq(60,0);

        for(auto it : t)
        {
            t_freq[it-'A']++;
        }    

        int lo = 0;
        int hi = 0;
        int n = s.length();

        string ans = "";

        while(hi < n)
        {
            s_freq[s[hi]-'A']++;

            while(satisfies(s_freq,t_freq) && s_freq[s[lo]-'A']-1 >= t_freq[s[lo]-'A'])
            {
                s_freq[s[lo]-'A']--;
                lo++;
            }

            if(satisfies(s_freq,t_freq))
            {
                if(ans == "" || ans.length() > hi-lo+1)
                {
                    ans = s.substr(lo,hi-lo+1);
                }
            }

            hi++;
        }

        return ans;
    }
};