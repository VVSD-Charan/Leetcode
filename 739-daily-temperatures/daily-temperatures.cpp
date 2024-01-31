class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();

        vector<int>waitTime(n);
        stack<int>st;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(st.size()>0 && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            if(st.size() == 0)
            {
                waitTime[i] = 0;
            }
            else
            {
                waitTime[i] = st.top() - i;
            }

            st.push(i);
        }    

        return waitTime;
    }
};