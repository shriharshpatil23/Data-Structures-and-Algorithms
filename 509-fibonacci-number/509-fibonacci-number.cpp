class Solution {
public:
    int t[31];
    
    int helper(int n){
        if(n==0)    return 0;
        if(n==1)    return 1;
        
        if(t[n]!= -1)   return t[n];
        
        return t[n] = helper(n-1)+helper(n-2);
    }
    
    int fib(int n) {
        memset(t,-1,sizeof(t));
        return helper(n);
    }
};