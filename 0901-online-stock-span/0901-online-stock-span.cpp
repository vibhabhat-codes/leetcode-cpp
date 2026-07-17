class StockSpanner {
public:
   stack<pair<int,int>> st;
   int index;
    StockSpanner() {
        index=0;
            
        
    }
    
    int next(int price) {
        while (!st.empty() && price >= st.top().first) {
            st.pop();
        }

        int span;

        if (st.empty()) {
            span = index + 1;
        }
        else {
            span = index - st.top().second;
        }

        st.push({price, index});

        index++;

        return span; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */