class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        queue<int>q;
        for(auto it : students)q.push(it);    

        for(int i = 0 ; i < sandwiches.size() ; i++)
        {
            int nodes = q.size();

            while(nodes > 0 && q.front() != sandwiches[i])
            {
                q.push(q.front());
                q.pop();

                nodes = nodes - 1;
            }

            if(nodes > 0)q.pop();
            else return (int)q.size();
        }

        return (int)q.size();
    }
};