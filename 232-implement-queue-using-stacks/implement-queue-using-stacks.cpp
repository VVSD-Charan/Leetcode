class MyQueue {
    
    stack<int>s1;
    stack<int>s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size() > 1){
            s2.push(s1.top());
            s1.pop();
        }

        int number = s1.top();  s1.pop();

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }

        return number;
    }
    
    int peek() {
        int number = -1;

        while(s1.size() > 1){
            s2.push(s1.top());
            s1.pop();
        }

        number = s1.top();

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }

        return number;
    }
    
    bool empty() {
        return (s1.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */