class Solution {

    int getNumber(string &s)
    {
        int sum = 0;

        for(int i = 0 ; i < s.length() ; i++)
        {
            sum = sum*10 + (s[i] - '0');
        }

        return sum;
    }
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        queue<string>q;

        for(char i = '1' ; i <= '9' ; i++)
        {
            string str(1,i);
            q.push(str);
        }    

        vector<int>answers;

        while(q.size())
        {
            string str = q.front();     q.pop();
            int number = getNumber(str);

            if(number > high)continue;
            if(number >= low && number <= high)answers.push_back(number);

            char ch = str.back();
            if(ch == '9')continue;

            ch++;
            q.push(str + ch);
        }

        return answers;
    }
};