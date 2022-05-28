class Solution {
public:
    int missingNumber(vector<int>& nums) {
       long long sum = 0;
        int n = nums.size();
        for(auto x : nums){
            sum += x;
        }
        return (n*(n+1)/2) - sum ;
    }
};