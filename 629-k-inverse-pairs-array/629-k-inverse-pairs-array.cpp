class Solution {
public:
     const int M = 1e9+7;
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
       for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else{
                    int sum=(dp[i-1][j]+M-((j-i)>=0 ? dp[i-1][j-i] : 0))%M;  
                    dp[i][j]=(dp[i][j-1]+sum)%M;
                }
            }
        }
        return (dp[n][k]+ M-((k-1)>=0 ? dp[n][k-1] : 0))%M;
    }
};