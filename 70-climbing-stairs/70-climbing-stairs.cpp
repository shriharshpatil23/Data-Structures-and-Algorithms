class Solution {
public:
    int t[46];
    
    int helper(int n){
        //base cases
        if(n==0)    return 1;
        
        if(n < 0)   return 0;
        //overlapping subproblem
        if(t[n]!= -1)   return  t[n];
        //one step
        int one = helper(n-1);
        //two steps
        int tw0 = helper(n-2);
        
        return t[n] = one + tw0;
    }
    
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return helper(n);
    }
};