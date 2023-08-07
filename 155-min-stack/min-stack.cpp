class MinStack {
    stack<long long int>st;
    long long mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push(val);
            mini = val;
            return;
        }

        if(val >= mini){
            st.push(val);
            return;
        }

        long long num = (long long)((long long)2*val) - mini;
        st.push(num);
        mini = val;
    }
    
    void pop() {
        if(st.size() == 0)return;

        if(st.top() > mini)
        {
            st.pop();
            return;
        }

        long long val = 2*mini - st.top();
        mini = val;
        st.pop();
    }
    
    int top() {
        if(st.size() == 0)return -1;

        if(st.top() > mini)
        {
            return st.top();
        }

        return (int)mini;
    }
    
    int getMin() {
        if(st.size() == 0)return -1;

        return (int)mini;
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