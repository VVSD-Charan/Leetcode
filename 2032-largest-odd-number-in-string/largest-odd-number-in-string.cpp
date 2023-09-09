class Solution {

public:
    string largestOddNumber(string num) 
    {
        string ans = "";
        int first_index = 0;

        while(first_index < num.length() && num[first_index] == '0')first_index++;

        string curr = "";

        for(int i = first_index ; i < num.length() ; i++)
        {
           curr.push_back(num[i]);
           int number = (num[i] - '0');

           if((number%2) == 1)
           {
               ans = curr;
           }
        }

        return ans;    
    }
};