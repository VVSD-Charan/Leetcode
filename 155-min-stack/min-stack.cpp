class MinStack {

    stack<long long>s;
    long long mini = 1e10;

public:
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(s.size() == 0)
        {
            mini = val;
            s.push(val);
            return;
        }

        if(val > mini)
        {
            s.push(val);
        }    
        else
        {
            long long x = (long long)((long long)2*val) - mini;
            s.push(x);
            mini = val;
        }
    }
    
    void pop() 
    {
        if(s.size() == 0)return;

        if(s.top() < mini)
        {
            mini = 2*mini*1LL - s.top();
        }    

        s.pop();
    }
    
    int top() 
    {
        if(s.size() == 0)return 0;

        if(s.top() < mini)return mini;
        return s.top();
    }
    
    int getMin() 
    {
        if(s.size() == 0)return -1;
        return mini;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */