class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        stack<int> st;
        int n = colors.size();
        for(int i=0;i<n;i++){
            if(st.empty() || colors[st.top()]!=colors[i]){
                st.push(i);
            }else{
                if(neededTime[i]>neededTime[st.top()]){
                    cost += neededTime[st.top()];
                    st.pop();
                    st.push(i);
                }else{
                    cost+= neededTime[i];
                }
            }
        }
        return cost;
    }
};