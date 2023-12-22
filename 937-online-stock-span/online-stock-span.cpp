class StockSpanner {
    stack<pair<int,int>>st;
    int idx;
    
public:
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) 
    {
        while(st.size()>0 && st.top().second <= price)
        {
            st.pop();
        }    

        idx++;
        if(st.size() == 0)
        {
            st.push({idx,price});
            return idx;
        }
        int ans = idx - st.top().first;
        st.push({idx,price});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */