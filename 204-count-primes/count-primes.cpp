class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool>coprime(n+1,false);
        int counter = 0;

        for(int i = 2 ; i < n ; i++)
        {
            if(coprime[i] == false)
            {
                counter++;

                for(long j = (long)i*(long)i ; j < n ; j+=i)
                {
                    coprime[j] = true;
                }
            }
        }

        return counter;
    }
};