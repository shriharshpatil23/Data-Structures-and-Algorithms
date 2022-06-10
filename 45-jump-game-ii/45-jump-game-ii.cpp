class Solution {
public: int t[10001];
    int helper(int i, vector<int> &nums){
        if(i>=nums.size()-1)    return 0;
        
        
        if(t[i]!= -1)   return t[i];
        
        int max_step = nums[i];
        int ans = INT_MAX-2;
        for(int j=1;j<=max_step;j++){
            ans =  min(ans,1+helper(i+j,nums));
        }
        return t[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,nums);
    }
};