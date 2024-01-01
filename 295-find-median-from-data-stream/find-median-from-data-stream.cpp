class MedianFinder {

    priority_queue<int,vector<int>,greater<int>>great;
    priority_queue<int>small;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(small.size() > great.size())
        {
            if(num < small.top())
            {
                great.push(small.top());
                small.pop();

                small.push(num);
            }
            else
            {
                great.push(num);
            }
        }
        else
        {
            if(small.size() == 0 || small.top() > num)
            {
                small.push(num);
            }
            else
            {
                great.push(num);

                small.push(great.top());
                great.pop();
            }
        }
    }
    
    double findMedian() 
    {
        if(small.size() == great.size())
        {
            double median = ((double)small.top() + (double)great.top())/2.0;
            return median;
        }    

        return (double)small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */