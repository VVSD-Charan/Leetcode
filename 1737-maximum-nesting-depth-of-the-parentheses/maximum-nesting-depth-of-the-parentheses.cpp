class Solution {
public:
    int maxDepth(string s) 
    {
        int open = 0;
        int max_length = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            open += (s[i] == '(');
            open -= (s[i] == ')');

            max_length = max(max_length,open);
        }

        return max_length;
    }
};