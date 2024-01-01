class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int count_5 = 0;
        int count_10 = 0;

        for(int i = 0 ; i < bills.size() ; i++)
        {
            if(bills[i] == 5)
            {
                count_5 = count_5 + 1;
            }
            else if(bills[i] == 10)
            {
                if(count_5 == 0)return false;

                count_5 = count_5 - 1;
                count_10 = count_10 + 1;
            }
            else
            {
                if(count_10 > 0 && count_5 > 0)
                {
                    count_10 = count_10 - 1;
                    count_5 = count_5 - 1;
                }
                else if(count_5 > 2)
                {
                    count_5 = count_5 - 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;    
    }
};