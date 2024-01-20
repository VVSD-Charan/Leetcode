class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        int modd = 1e9+7;

        vector<int>prefix(n);
        vector<int>suffix(n);

        stack<int>pre;
        stack<int>next;

        for(int i = 0 ; i < n ; i++)
        {
            while(pre.size()>0 && arr[pre.top()] >= arr[i])
            {
                pre.pop();
            }

            if(pre.size() == 0)
            {
                prefix[i] = i+1;
            }
            else
            {
                prefix[i] = i - pre.top();
            }

            pre.push(i);
        }    

        for(int i = n-1 ; i >= 0 ; i--)
        {
            while(next.size()>0 && arr[next.top()] > arr[i])
            {
                next.pop();
            }

            if(next.size() == 0)
            {
                suffix[i] = n - i;
            }
            else
            {
                suffix[i] = next.top() - i;
            }

            next.push(i);
        }

        int sum = 0;

        for(int i = 0 ; i < n ; i++)
        {
            long long product = (((long long)prefix[i]*(long long)suffix[i])%modd);
            product = ((product * (long long)arr[i])%modd);

            sum = (sum + (product%modd))%modd;
        }

        return sum;
    }
};