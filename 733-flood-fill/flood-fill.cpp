class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(image[sr][sc]==color)return image;

        int c = image[sr][sc];
        image[sr][sc]=color;

        queue<pair<int,int>>q;
        q.push({sr,sc});

        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};

        while(q.size())
        {
            auto it = q.front();   q.pop();
            int x = it.first;
            int y = it.second;

            for(int i=0;i<4;i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx>=0 && cy>=0 && cx<image.size() && cy<image[0].size() && image[cx][cy]==c)
                {
                    image[cx][cy]=color;
                    q.push({cx,cy});
                }
            }
        }

        return image;
    }
};