class Solution {
public:
    string reverseWords(string s) 
    {
        int l = 0;
        int r = s.length()-1;

        while(r >= l && s[r] == ' ')r--;
        while(l <= r && s[l] == ' ')l++;

        string curr = "";
        string ans = "";

        while(r >= l)
        {
            if(s[r] == ' ')
            {
                reverse(curr.begin(),curr.end());
                ans += curr;

                while(r >= l && s[r] == ' ')r--;

                if(r >= l)
                {
                    ans.push_back(' ');
                }
                curr = "";
            }
            else
            {
                curr.push_back(s[r--]);
            }
        }

        reverse(curr.begin(),curr.end());
        ans += curr;

        return ans; 
    }
};