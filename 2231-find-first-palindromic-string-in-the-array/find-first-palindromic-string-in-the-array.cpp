class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(int i = 0 ; i < words.size() ; i++)
        {
            int lo = 0;
            int hi = words[i].length()-1;

            while(lo <= hi && words[i][lo] == words[i][hi])
            {
                lo = lo + 1;
                hi = hi - 1;
            }

            if(lo > hi)return words[i];
        }    

        return "";
    }
};