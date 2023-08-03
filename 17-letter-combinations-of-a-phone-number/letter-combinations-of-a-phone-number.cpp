class Solution {
public:

    void f(string digits,vector<string>&ans,unordered_map<int,string>&mp,int idx,queue<string>&q)
    {
        if(idx == digits.length())
        {
            while(q.size())
            {
                ans.push_back(q.front());
                q.pop();
            }

            return;
        }

        int nodes = q.size();

        while(nodes--)
        {
            string node = q.front();  q.pop();
            string str = mp[digits[idx]-'0'];

            for(int i = 0; i < str.length() ; i++)
            {
                q.push(node + str[i]);
            }
        }

        f(digits,ans,mp,idx+1,q);
    }

    vector<string> letterCombinations(string digits) 
    {
        if(digits.length()==0)return {};
        
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        queue<string>q;  q.push("");
        vector<string>ans;
        f(digits,ans,mp,0,q); 

        return ans;   
    }
};