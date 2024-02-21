class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        int res_and = 0;

        for(int i = 31 ; i >= 0 ; i--)
        {
            int number = (1 << i);
            int res1 = (number & left);
            int res2 = (number & right);

            if(res1 && res2 && right-left <= number)
            {
                res_and += number;
            }
        }    

        return res_and;
    }
};