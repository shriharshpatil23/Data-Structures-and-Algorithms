class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            if(nums[0]>0){
                return 1;
            }else{
                return 0;
            }
        }
       int sign = 1;
        int count = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count=0;
                sign = 1;
                continue;
            }
            count++;
            if(nums[i]<0){
                sign *= -1;
            }
            if(sign == 1){
                ans = max(count,ans);
               // sign = 1;
            }
         }
        count = 0; 
        sign = 1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                count=0;
                sign = 1;
                continue;
            }
            count++;
            if(nums[i]<0){
                sign *= -1;
            }
            if(sign == 1){
                ans = max(count,ans);
               // sign = 1;
            }
        }
        return ans;
    }
};