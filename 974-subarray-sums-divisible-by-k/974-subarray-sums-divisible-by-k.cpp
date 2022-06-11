class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        vector<int> rem(n);
        int ans = 0;
        int preSum =0;
        for(int i=0;i<n;i++){
            preSum += nums[i];
            int rem = preSum % k;
            if(rem < 0) rem += k;
            if(m.find(rem)!=m.end()){
                ans += m[rem];
            }
            
            m[rem]++;
        }
        return ans;    
    }
};