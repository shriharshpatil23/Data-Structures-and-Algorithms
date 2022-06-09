class Solution {
public:
    int t[20002];
    
    int helper(int idx , vector<int> arr){
        if(idx <= 0)    return 0;
        
        if(t[idx]!= -1) return t[idx];
        
        int take = idx*arr[idx] + helper(idx-2,arr);
        
        int not_take = helper(idx-1,arr);
        
        return t[idx] = max(take,not_take);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001,0);
        int max_val = INT_MIN;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            max_val = max(max_val,nums[i]);
        }
        memset(t,-1,sizeof(t));
        return helper(max_val,arr);
    }
};