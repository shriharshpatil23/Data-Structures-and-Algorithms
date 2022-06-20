class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i ;
    StockSpanner() {
        i =0;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,i++});
            return 1;
        }else{
            while(!st.empty() &&   price >= st.top().first)    st.pop();
            
            int res = 0;            
            if(!st.empty()) res = i - st.top().second;
            else    res = i + 1;
            
            st.push({price,i++});
            return res;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */