class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count_ones = 0;

        while(n > 0)
        {
            count_ones += (n % 2);
            n = (n / 2);
        }    

        return count_ones;
    }
};