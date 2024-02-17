class Solution {

    bool canReach(vector<int>&diff,int mid,int bricks,int ladders)
    {
        priority_queue<int>pq;

        for(int i = 0 ; i < mid ; i++)
        {
            if(diff[i] > 0)
            {
                pq.push(diff[i]);
            }
        }

        while(pq.size())
        {
            int req = pq.top();     pq.pop();

            if(ladders > 0)
            {
                ladders--;
            }
            else
            {
                if(bricks < req)return false;

                bricks -= req;
            }
        }

        return true;
    }

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int lo = 0;
        int hi = heights.size()-1;

        vector<int>diff;
        for(int i = 1 ; i < heights.size() ; i++)
        {
            diff.push_back(max(heights[i]-heights[i-1],0));
        }

        while(hi - lo > 1)
        {
            int mid = (lo + hi)>>1;

            if(canReach(diff,mid,bricks,ladders))
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }    

        if(canReach(diff,hi,bricks,ladders))return hi;
        return lo;
    }
};