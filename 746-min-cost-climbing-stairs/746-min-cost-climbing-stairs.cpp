class Solution {
public:
    int t[1001];
    
    int helper(int n,vector<int>& cost ){
        if(n==0 || n==1 )   return cost[n];
        
        if(n<0) return 0;
        
        if(t[n]!= -1)   return t[n];
            
        //one step;
        int one = cost[n] + helper(n-1,cost);
        //two steps
        int two = cost[n] + helper(n-2,cost);
        
        return t[n] = min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t));
        int n = cost.size();
        return min(helper(n-1,cost),helper(n-2,cost));
    }
};