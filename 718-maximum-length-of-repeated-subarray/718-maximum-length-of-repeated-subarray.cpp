class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int ans = 0;
    int helper(int i, int j, vector<int>&nums1,vector<int>&nums2){
        if(i>=m || j>=n)    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        helper(i+1,j,nums1,nums2);
        helper(i,j+1,nums1,nums2);
        
        if(nums1[i]==nums2[j]){
            dp[i][j] = 1 + helper(i+1,j+1,nums1,nums2);
        }else{
            dp[i][j]=0;
        }
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(dp,-1,sizeof(dp));
        helper(0,0,nums1,nums2);
        return ans;
    }
};