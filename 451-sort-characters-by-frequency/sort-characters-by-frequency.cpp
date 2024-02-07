class Solution {

    static bool cmp(const pair<int,char>&a,const pair<int,char>&b)
    {
        if(a.first > b.first)return true;
        if(a.first < b.first)return false;

        return (a.second < b.second);
    }

public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>freq;

        for(int i = 0 ; i < s.length() ; i++)
        {
            freq[s[i]]++;
        }   

        vector<pair<int,char>>vp;

        for(auto it : freq)
        {
            vp.push_back({it.second,it.first});
        }

        sort(vp.begin(),vp.end(),cmp);

        string str = "";

        for(int i = 0 ; i < vp.size() ; i++)
        {
            while(vp[i].first > 0)
            {
                vp[i].first--;
                str.push_back(vp[i].second);
            }
        }

        return str;
    }
};