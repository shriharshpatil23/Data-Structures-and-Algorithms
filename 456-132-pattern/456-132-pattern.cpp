class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // for(int i=1;i<nums.size()-1;i++){
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1] && nums[i+1]>nums[i-1])  return true;
        // }
        // return false;
        int n = nums.size();
        int prev = INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<prev)  return true;
            while(!st.empty() && st.top()<nums[i]){
                prev = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};