class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
       sort(g.begin(),g.end());
       priority_queue<int,vector<int>,greater<int>>pq;

        for(int i = 0 ; i < s.size() ; i++)
        {
            pq.push(s[i]);
        }

        int content = 0;

        for(int i = 0 ; i < g.size() ; i++)
        {
            while(pq.size()>0 && pq.top()<g[i])
            {
                pq.pop();
            }

            if(pq.size() > 0)
            {
                content++;
                pq.pop();
            }
        }

        return content;
    }
};