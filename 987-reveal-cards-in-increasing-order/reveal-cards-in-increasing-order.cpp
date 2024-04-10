class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        if(deck.size() == 1)return deck;

        sort(deck.begin(),deck.end());

        int n = deck.size();
        int last_index = n - 3;

        deque<int>dq;   
        dq.push_back(deck[n-2]);
        dq.push_back(deck[n-1]);

        while(last_index >= 0)
        {
            dq.push_front(dq.back());
            dq.pop_back();

            dq.push_front(deck[last_index--]);
        }

        for(int i = 0 ; i < n ; i++)
        {
            deck[i] = dq.front();   dq.pop_front();
        }

        return deck;
    }
};