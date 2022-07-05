class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, n = nums.size();
        int sum = 0;
        int rightSum = 0;
        for(auto x : nums)  sum += x;
        
        rightSum = sum;
        
        for(int i= 0;i<n;i++){
            rightSum -= nums[i];
            
            if(rightSum == leftSum) return i;
            
            leftSum += nums[i];
        }
        return -1;
    }
};