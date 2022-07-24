class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(),len = 0;
        for(int i= 0;i<n;i++){
            if(nums[i] != 0) len = 0;
            else len++;
            ans += len;
        }
        return ans;
    }
};