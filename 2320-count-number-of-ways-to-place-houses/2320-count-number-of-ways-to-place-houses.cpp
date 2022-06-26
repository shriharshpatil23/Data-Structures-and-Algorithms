class Solution {
public:
    int t[10001];
    long long  mod=1e9+7;
    long long helper(int i,int n)
    {
        if(i>=n)    return 1;           //we traverse whole array
        if(t[i]!=-1)    return t[i];
        int take=helper(i+2,n)%mod;     //if we select the Plot
        int notake=helper(i+1,n)%mod;   //if we skip it
        return t[i]=(take+notake)%mod;
    }
    int countHousePlacements(int n) {
        memset(t,-1,sizeof(t));
        long long  ans=helper(0,n);
        return ((ans%mod)*(ans%mod))%mod;
    }

};