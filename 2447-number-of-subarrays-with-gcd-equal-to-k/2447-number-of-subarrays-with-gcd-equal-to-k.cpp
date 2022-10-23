class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int GCD = nums[i];
            for(int j=i;j<n;j++){
                GCD = gcd(GCD,nums[j]);
                if(GCD==k)  ans++;
            }
        }
        return ans;
    }
};