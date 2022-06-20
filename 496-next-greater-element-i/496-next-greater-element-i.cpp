class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        vector<int> ngr;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(st.top() > nums2[i]){
                    ngr.push_back(st.top());
                    st.push(nums2[i]);
                    break;
                }
                st.pop();                
            }
            if(st.empty()){
                ngr.push_back(-1);
                st.push(nums2[i]);
            }  
        }
        reverse(ngr.begin(),ngr.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums2[i]]=ngr[i];
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};