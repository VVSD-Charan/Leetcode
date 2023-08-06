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
        if(s1.size() == 0)return -1;

        while(s1.size() != 1){
            s2.push(s1.top());  s1.pop();
        }

        int number = s1.top();  s1.pop();

        while(s2.size() > 0){
            s1.push(s2.top());  s2.pop();
        }

        return number;
    }
    
    int peek() {
        if(s1.size() == 0)return -1;

        int number;

        while(s1.size() > 0){
            number = s1.top();
            s2.push(s1.top());  s1.pop();
        }

        while(s2.size() > 0){
            s1.push(s2.top());  s2.pop(); 
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