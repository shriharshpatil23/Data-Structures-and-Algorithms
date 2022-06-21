class MinStack {
public:
    stack<int> st;
    stack<int> mst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mst.empty()) mst.push(val);
        else{val = min(val,mst.top());
             mst.push(val);
             }
    }
    
    void pop() {
        mst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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