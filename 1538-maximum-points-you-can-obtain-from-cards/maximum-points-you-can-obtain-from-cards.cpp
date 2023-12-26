class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {    
        int total_sum = 0;
        int max_sum = 0;
        
        for(int i = 0 ; i < k ; i++)
        {
            total_sum = total_sum + cardPoints[i];
        }

        max_sum = max(max_sum,total_sum);

        int lo = k-1;
        int hi = cardPoints.size()-1;

        while(lo >= 0)
        {
            total_sum -= cardPoints[lo];
            total_sum += cardPoints[hi];

            max_sum = max(max_sum,total_sum);

            lo--;
            hi--;
        }

        return max_sum;
    }
};