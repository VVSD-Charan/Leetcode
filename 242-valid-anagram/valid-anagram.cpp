class Solution {
public:
    bool isAnagram(string s, string t) 
    {
       if(s.length() != t.length())return false;

       int arr[26];
       memset(arr,0,sizeof arr);

       for(int i = 0 ; i < s.length() ; i++)
       {
           arr[s[i]-'a']++;
       }

       for(int i = 0 ; i < t.length() ; i++)
       {
           if(arr[t[i]-'a'] == 0)return false;

           arr[t[i]-'a']--;
       }

       return true;
    }
};