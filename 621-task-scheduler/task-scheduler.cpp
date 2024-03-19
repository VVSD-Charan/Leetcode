class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int>pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int res = 0;

        while(pq.size() > 0){
            int nonused = n + 1;
            int used = 0;

            vector<int>temp;

            while(pq.size() > 0 && nonused > 0){
                temp.push_back(pq.top());
                pq.pop();

                nonused--;
                used++;
            }

            res += used;

            for(int i = 0; i < used; i++){
                if(temp[i] == 1){
                    continue;
                }
                pq.push(temp[i] - 1);
            }

            if(pq.size() > 0){
                res += nonused;
            }
        }

        return res;
    }
};