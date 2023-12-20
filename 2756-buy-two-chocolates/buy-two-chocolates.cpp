class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        int first_min = INT_MAX;
        int second_min = INT_MAX;

        for(int i = 0 ; i < prices.size() ; i++)
        {
            if(prices[i] <= first_min)
            {
                second_min = first_min;
                first_min = prices[i];
            }
            else if(prices[i] < second_min)
            {
                second_min = prices[i];
            }
        }

        if(first_min + second_min > money)
        {
            return money;
        }    

        return money-first_min-second_min;
    }
};