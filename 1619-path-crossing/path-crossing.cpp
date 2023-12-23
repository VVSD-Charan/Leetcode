class Solution {
public:
    bool isPathCrossing(string path) 
    {
        int x = 0;
        int y = 0;

        set<pair<int,int>>s;
        s.insert({x,y});

        for(char it : path)
        {
            x += (it == 'E');
            x -= (it == 'W');
            y += (it == 'N');
            y -= (it == 'S');

            if(s.find({x,y}) != s.end())
            {
                return true;
            }
            s.insert({x,y});
        }

        return false;
    }
};