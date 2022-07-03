class Solution {
public:
    int t[1001];
    int mod ;
    int helper(int curr,int n, int delay, int forgot){
        int ans = 0;
        
        if(t[curr]!=-1)    return t[curr]%mod;
        
        for(int i = curr;i<=n;i++){
            if(i - curr == forgot){
                ans--;
                break;
            }
            if(i - curr >= delay){
                ans = (ans%mod + (1 + (helper(i,n,delay,forgot)%mod)))%mod;
            }
        }
        return t[curr] = ans%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(t,-1,sizeof(t));
        mod = 1000000007;
        return (helper(1,n,delay,forget)+1)%mod;
    }
};