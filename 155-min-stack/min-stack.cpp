class MinStack {

    long minElement;
    stack<long>s;

public:
    MinStack() {
        minElement = INT_MAX;
    }
    
    void push(int val) 
    {
        if(s.size() == 0)
        {
            s.push(val);
            minElement = val;
            return;
        }    

        if(val < minElement)
        {
            s.push((long)2*(long)val - minElement);
            minElement = val;
        }
        else
        {
            s.push(val);
        }
    }
    
    void pop() 
    {
        if(s.size() == 1)
        {
            s.pop();
            return;
        }    

        if(s.top() < minElement)
        {
            minElement = (long)2*(long)minElement - s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    
    int top() 
    {
        if(s.top() < minElement)
        {
            return minElement;
        }    
        return s.top();
    }
    
    int getMin() 
    {
        return minElement;    
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