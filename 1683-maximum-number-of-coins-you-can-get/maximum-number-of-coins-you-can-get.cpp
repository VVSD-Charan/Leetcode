class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end(),greater<int>());

        int total_coins = 0;

        int l = 1;
        int r = piles.size()-1;

        while(l < r)
        {
            total_coins += piles[l];

            l = l + 2;
            r--;
        }

        return total_coins;
    }
};