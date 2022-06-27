class Solution {
public:
    int dp[70];
    int f(int n){
        if(n<1)return 0;
        if(n==1 or n==2)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans = 0;
        for(int k=1;k<n;k++)ans = max({ans,k*f(n-k),k*(n-k)});
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};