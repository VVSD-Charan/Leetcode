class Solution {

    long long subarrayMin(vector<int>&nums)
    {
        vector<long long>prefix(nums.size());
        vector<long long>suffix(nums.size());

        stack<int>pre;
        stack<int>next;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            while(pre.size() > 0 && nums[pre.top()] >= nums[i])
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

        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            while(next.size()>0 && nums[next.top()] > nums[i])
            {
                next.pop();
            }

            if(next.size() == 0)
            {
                suffix[i] = nums.size() - i;
            }
            else
            {
                suffix[i] = next.top() - i;
            }
            next.push(i);
        }

        long long sum = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += (((long long)nums[i])*(prefix[i] * suffix[i]));
        }

        return sum;
    }

     long long subarrayMax(vector<int>&nums)
    {
        vector<long long>prefix(nums.size());
        vector<long long>suffix(nums.size());

        stack<int>pre;
        stack<int>next;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            while(pre.size() > 0 && nums[pre.top()] <= nums[i])
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

        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            while(next.size()>0 && nums[next.top()] < nums[i])
            {
                next.pop();
            }

            if(next.size() == 0)
            {
                suffix[i] = nums.size() - i;
            }
            else
            {
                suffix[i] = next.top() - i;
            }
            next.push(i);
        }

        long long sum = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum += (((long long)nums[i])*(prefix[i] * suffix[i]));
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long max_sum = subarrayMax(nums);
        long long min_sum = subarrayMin(nums);

        return (max_sum - min_sum);    
    }
};