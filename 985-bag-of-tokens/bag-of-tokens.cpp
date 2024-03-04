class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int current_score = 0;
        int max_score = 0;
        
        sort(tokens.begin(),tokens.end());

        int lo = 0;
        int hi = tokens.size()-1;

        while(lo <= hi)
        {
            if(power >= tokens[lo])
            {
                power = power - tokens[lo];
                current_score = current_score + 1;
                max_score = max(max_score,current_score);
                lo = lo + 1;
            }
            else if(current_score > 0)
            {
                power = power + tokens[hi];
                current_score = current_score - 1;
                hi = hi - 1;
            }
            else
            {
                break;
            }
        }

        return max_score;    
    }
};