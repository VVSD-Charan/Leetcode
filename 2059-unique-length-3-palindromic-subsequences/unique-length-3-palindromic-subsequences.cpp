class Solution {

    bool present(vector<int>&arr,int l,int r)
    {
       auto it = upper_bound(arr.begin(),arr.end(),l);

       if(it == arr.end())return false;

       return (*it < r);
    }

public:
    int countPalindromicSubsequence(string s) 
    {
        vector<vector<int>>arr(26);

        for(int i = 0 ; i < s.length() ; i++)
        {
            arr[s[i]-'a'].push_back(i);
        }    

        int palindromes=0;

        for(char i = 'a' ; i <= 'z' ; i++)
        {
            if(arr[i-'a'].size() >= 2)
            {
                for(char j = 'a' ; j <= 'z' ; j++)
                {
                    if(arr[j-'a'].size()>0 && present(arr[j-'a'],arr[i-'a'][0],arr[i-'a'].back()))
                    {
                        palindromes++;
                    }
                }
            }
        }

        return palindromes;
    }
};