class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        set<string>s(wordList.begin(),wordList.end());
        if(beginWord == endWord)return 0;
        if(s.find(endWord)==s.end())return 0;

        queue<string>q;
        q.push(beginWord);

        if(s.find(beginWord)!=s.end())s.erase(s.find(beginWord));

        int changes = 0;

        while(q.size() && s.size())
        {
            int nodes = q.size();
            changes++;

            while(nodes--)
            {
                string str = q.front();  q.pop();

                for(int i=0;i<str.length();i++)
                {
                    char initial = str[i];
                    for(char j ='a';j<='z';j++)
                    {
                        str[i] = j;
                        if(s.find(str)!=s.end())
                        {
                            s.erase(s.find(str));
                            q.push(str);

                            if(str == endWord)return changes+1;
                        }
                    }
                    str[i]=initial;
                }
            }
        }

        return 0;
    }
};