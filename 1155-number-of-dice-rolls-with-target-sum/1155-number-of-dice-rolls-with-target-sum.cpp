class Solution {
public:
    long long MOD = 1000000007;
    int dp[31][1001];
    int helper( int n, int k, int target){
        if(n==0 && target==0) return 1;
        
        if(n<=0 || target <=0)    return 0;
        
        if(dp[n][target]!=-1)   return dp[n][target];
        
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans = (ans%MOD + helper(n-1,k,target-i)%MOD)%MOD;
        }
        return dp[n][target] = ans%MOD;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(d,f,target);
    }
};