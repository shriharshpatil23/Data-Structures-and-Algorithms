class Solution {
public:
    int t[2501][2501];
    
    int helper(int i , int p, vector<int>& nums ){
        if(i==nums.size())  return 0;
    
        if( t[i][p+1] != -1){
            return t[i][p+1];
        }
    
    int take = 0;
    if( p==-1 || nums[i] > nums[p]) take = 1 + helper(i+1,i,nums);
      
    int not_take = helper(i+1,p,nums);
    
    return t[i][p+1] = max(take,not_take);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,-1,nums);
    }
};