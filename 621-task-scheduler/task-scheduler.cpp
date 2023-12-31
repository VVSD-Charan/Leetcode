class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int>freq(26,0);

        for(int i = 0 ; i < tasks.size() ; i++)
        {
            freq[tasks[i]-'A']++;
        }    

        priority_queue<int>pq;

        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i] > 0)
            {
                pq.push(freq[i]);
            }
        }

        int total_time = 0;

        while(pq.size() > 0)
        {
            int empty_slots = n+1;
            int filled_slots = 0;

            vector<int>temp_tasks;

            while(pq.size()>0 && empty_slots>0)
            {
                temp_tasks.push_back(pq.top());
                pq.pop();

                empty_slots--;
                filled_slots++;
            }

            total_time += filled_slots;

            for(auto it : temp_tasks)
            {
                if(it == 1)continue;
                pq.push(it-1);
            }

            if(pq.size() > 0)total_time += empty_slots;
        }

        return total_time;
    }
};