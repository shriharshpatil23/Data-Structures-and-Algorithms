class Solution {
public:
    int t[10001];
    bool helper(int i, vector<int>& nums){
        if(i>=nums.size()-1)    return true;
        if(nums[i]==0)  return false;
        
        if(t[i]!= -1) return t[i];
        
        int max_jump = nums[i];
        bool ans = false;
        for(int j=1;j<=max_jump;j++){
           if(helper(i+j,nums)) return t[i]=true;
        }
        return t[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,nums);
    }
};