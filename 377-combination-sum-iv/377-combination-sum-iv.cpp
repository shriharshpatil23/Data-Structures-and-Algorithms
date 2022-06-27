class Solution {
public:
   int t[1002][1002];
    
    int helper(int i,vector<int>& nums, int target){
        
        if(target==0)   return 1;
        
        if(i == -1 )    return 0;
        
        if(t[i][target]!=-1)    return t[i][target];
        
        int ans = helper(i-1,nums,target);
       
        if(nums[i]<=target){
            ans += helper(nums.size()-1,nums,target-nums[i]);
        }
        return t[i][target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return  helper(n-1,nums,target);;
    }
};