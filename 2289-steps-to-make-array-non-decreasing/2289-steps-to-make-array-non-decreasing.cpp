class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
       vector<int> a(n); 
        int ans = 0; 
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && nums[i]>nums[s.top()]){
                a[i] = max(a[i]+1, a[s.top()]); 
                s.pop();
            }
            s.push(i);
            ans = max(ans, a[i]);
        }
        return ans;
    }
};