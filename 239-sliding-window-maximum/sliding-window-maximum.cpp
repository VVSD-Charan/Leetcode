class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>arr;
        deque<int>dq;

        for(int i = 0 ; i < k - 1 ; i++)
        {
            while(dq.size() > 0 && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }  

        for(int i = k - 1 ; i < nums.size() ; i++)
        {
            while(dq.size() > 0 && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            while(dq.size() > 0 && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            arr.push_back(nums[dq.front()]);
        }

        return arr;
    }
};