class KthLargest {

    priority_queue<int,vector<int>,greater<int>>pq;
    int k_value;

public:
    KthLargest(int k, vector<int>& nums) {
        for(auto it : nums){
            pq.push(it);

            if(pq.size() > k)pq.pop();
        }

        k_value = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k_value)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */