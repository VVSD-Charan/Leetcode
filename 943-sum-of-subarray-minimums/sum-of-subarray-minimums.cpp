class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();

        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);

        stack<int>prevs;

        prevSmaller[0] = 1;
        prevs.push(0);

        for(int i = 1 ; i < n ; i++)
        {
            while(prevs.size() > 0 && arr[prevs.top()] > arr[i])
            {
                prevs.pop();
            }

            if(prevs.size() == 0)
            {
                prevSmaller[i] = i+1;
            }
            else
            {
                prevSmaller[i] = i-prevs.top();
            }

            prevs.push(i);
        }

        stack<int>next;

        nextSmaller[n-1] = 1;
        next.push(n-1);
        int m = 1e9+7;

        for(int i = n-2 ; i >= 0 ; i--)
        {
            while(next.size() > 0 && arr[next.top()] >= arr[i])
            {
                next.pop();
            }

            if(next.size() == 0)
            {
                nextSmaller[i] = n - i;
            }
            else
            {
                nextSmaller[i] = next.top() - i;
            }

            next.push(i);
        }

        int total_sum = 0;

        for(int i = 0 ; i < n ; i++)
        {
            long long product = ((prevSmaller[i] * nextSmaller[i])%m);
            long long mult = (((long long)arr[i]*product)%m);

            total_sum = (total_sum + mult)%m;
        }    

        return total_sum;
    }
};