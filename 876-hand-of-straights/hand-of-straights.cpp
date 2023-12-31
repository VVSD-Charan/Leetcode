class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        multiset<int>ms;

        int n = hand.size();
        int m = groupSize;

        if((n % m) > 0)return false;

        for(int i = 0 ; i < n ; i++)
        {
            ms.insert(hand[i]);
        }    

        sort(hand.begin(),hand.end());

        for(int i = 0 ; i < n ; i++)
        {
            if(ms.find(hand[i]) == ms.end())continue;

            for(int j = 0 ; j < m ; j++)
            {
                if(ms.find(hand[i]+j) == ms.end())return false;
                ms.erase(ms.find(hand[i]+j));
            }
        }

        return true;
    }
};