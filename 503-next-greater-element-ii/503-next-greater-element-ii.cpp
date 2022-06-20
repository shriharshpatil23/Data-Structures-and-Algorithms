class Solution {
public:
    vector<int> NGR(vector<int> nums){
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(st.top() > nums[i]){
                    ans.push_back(st.top());
                    st.push(nums[i]);
                    break;
                }
                st.pop();                
            }
            if(st.empty()){
                ans.push_back(-1);
                st.push(nums[i]);
            }  
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr ;
        arr = nums;
        int n = nums.size();
        for(auto x : nums){
            arr.push_back(x);
        }
        vector<int> ngr = NGR(arr);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=ngr[i];
        }
        return ans;
    }
};