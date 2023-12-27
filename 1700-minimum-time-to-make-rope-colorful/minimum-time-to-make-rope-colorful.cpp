class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        stack<int>st;

        int min_time = 0;

        for(int i = 0 ; i < colors.length() ; i++)
        {
            while(st.size()>0 && colors[i] == colors[st.top()] && neededTime[st.top()] <= neededTime[i])
            {
                min_time += neededTime[st.top()];
                st.pop();
            }

            if(st.size() > 0 && colors[i] == colors[st.top()] && neededTime[i] < neededTime[st.top()])
            {
                min_time += neededTime[i];
            }
            else
            {
                st.push(i);
            }
        }  

        return min_time;  
    }
};