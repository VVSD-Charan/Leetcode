class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int>dq;

        for(int i = 1 ; i <= n ; i++){
            dq.push_back(i);
        }

        while(dq.size() > 1){
            int moves = k-1;

            while(moves--){
                dq.push_back(dq.front());
                dq.pop_front();
            }

            dq.pop_front();
        }

        return dq.front();
    }
};