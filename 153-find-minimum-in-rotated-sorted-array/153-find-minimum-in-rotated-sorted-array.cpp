class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        
            if(n==1)    return nums[0];
        
          if(nums[0] < nums[n-1])
            return nums[0];
        
        int end = n - 1;
        int mid ;
        int ans = INT_MAX;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid]>=nums[0]){
                start = mid + 1;
            }else{
                ans = min(ans,nums[mid]);
                end = mid -1;
            }
        }
        return ans;
    }
};