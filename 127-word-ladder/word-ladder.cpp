class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if(beginWord.length()!=endWord.length())return 0;

        set<string>s;
        for(auto it : wordList){
            if(it.length()==beginWord.length()){
                s.insert(it);
            }
        }

        if(s.find(endWord)==s.end() || beginWord==endWord)return 0;
        if(s.find(beginWord)!=s.end())s.erase(s.find(beginWord));

        queue<string>q;   q.push(beginWord);
        int changes = 0;

        while(q.size()>0 && s.size()>0)
        {
            int nodes = q.size();
            changes++;

            while(nodes--)
            {
                string str = q.front();  q.pop();

                for(int i=0;i<str.length();i++)
                {
                    char initial = str[i];
                    for(char j='a';j<='z';j++)
                    {
                        str[i] = j;
                        if(str == endWord)return changes+1;
                        if(s.find(str)!=s.end())
                        {
                            s.erase(s.find(str));
                            q.push(str);
                        }
                    }
                    str[i] = initial;
                }
            }
        }

        return 0;
    }
};