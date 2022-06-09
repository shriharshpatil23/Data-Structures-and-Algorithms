class Solution {
public:
    int t[101];
    int t1[101];
    int helper1(int i, vector<int> nums){
        if(i>=nums.size())  return 0;
        if(t1[i]!= -1)   return t1[i];
        return t1[i]=max(nums[i] + helper1(i+2,nums), helper1(i+1,nums));
    }
    int helper(int i, vector<int> nums){
        if(i>=nums.size()-1)  return 0;
        if(t[i]!= -1)   return t[i];
        return t[i]=max(nums[i] + helper(i+2,nums), helper(i+1,nums));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        if(nums.size()==2)  return max(nums[0],nums[1]);
        memset(t,-1,sizeof(t));
        memset(t1,-1,sizeof(t1));
        return max(helper(0,nums),helper1(1,nums));
    }
};