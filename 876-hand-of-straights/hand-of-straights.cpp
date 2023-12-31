class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        map<int,int>mp;

        int n = hand.size();
        int m = groupSize;

        if((n % m) > 0)return false;

        for(int i = 0 ; i < n ; i++)
        {
            mp[hand[i]]++;
        }    

        for(auto it = mp.begin() ; it != mp.end() ; it++)
        {
           int freq = it->second;

           while(freq--)
           {
               for(int i = 0 ; i < m ; i++)
               {
                   if(mp[i + it->first] == 0)return false;
                   mp[i + it->first]--;
               }
           }
        }

        return true;

        return true;
    }
};