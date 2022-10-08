class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        int ans = nums[0]+nums[1]+nums[2];
        sort(begin(nums),end(nums));
        for(int i = 0 ; i < n-2 ; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;            
            while(j < k) {
                int curSum = nums[i]+nums[j]+nums[k];
                
                if(curSum == target) return curSum;
                
                if(abs(target-curSum)<abs(target-ans)) {
                    ans = curSum;
                }
                
                if(curSum > target) {
                    --k;
                }else{
                    ++j;
                }
            }
        }
        return ans;
    }
};