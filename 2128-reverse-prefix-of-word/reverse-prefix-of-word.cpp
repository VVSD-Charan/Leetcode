class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int index = 0;

        while(index < word.length() && word[index] != ch)
        {
            index = index + 1;
        }    

        if(index >= word.length())return word;

        int low = 0;
        int high = index;

        while(low < high)
        {
            swap(word[low],word[high]);
            low = low + 1;
            high = high - 1;
        }

        return word;
    }
};