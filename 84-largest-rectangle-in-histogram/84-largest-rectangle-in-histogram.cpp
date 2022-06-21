class Solution {
public:
    vector<int> nextSmaller(vector<int> heights){
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])    st.pop();
            
            if(!st.empty()) ans[i] = st.top();
            else    ans[i] = -1;
            
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSamller(vector<int> heights){
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])    st.pop();
            
            if(!st.empty()) ans[i] = st.top();
            else    ans[i] = -1;
            
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSamller(heights);
        
        int ans =  0, n = heights.size();
        for(int i=0;i<n;i++){
            if(next[i]==-1) next[i]=n;      //Very very imp step 
            int width = next[i] - prev[i] - 1;
            ans = max(ans, heights[i]*width);
        }
        return ans;
    }
};