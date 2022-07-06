class Solution {
public:
    int t[31];
    int helper(int n){
        //base case
        if(n==0)    return t[n] = 0;
        
        if(n==1)    return t[n] = 1;
        
        if(t[n]!= -1)   return t[n];
        
        return helper(n-1) + helper(n-2);
    }
    
    int fib(int n) {
        memset(t,-1,sizeof(t));
        return helper(n);
    }
};