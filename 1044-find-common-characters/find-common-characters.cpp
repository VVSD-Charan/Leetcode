class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(26,0));

        for(int i = 0 ; i < n ; i++)
        {
            for(auto it : words[i])
            {
                dp[i][it-'a']++;
            }
        }

        vector<string>ans;

        for(int i = 0 ; i < 26 ; i++)
        {
            int mini = INT_MAX;

            for(int j = 0 ; j < n ; j++)
            {
                mini = min(mini,dp[j][i]);
            }

            while(mini--)
            {
                string temp = "";
                temp.push_back('a'+i);

                ans.push_back(temp);
            }
        }

        return ans;
    }
};