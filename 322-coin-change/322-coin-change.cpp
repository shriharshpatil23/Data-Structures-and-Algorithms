class Solution {
public:
    int t[13][10001];
    
    int helper(int i , vector<int>& coins, int amount){
        if(i==0){
            if(amount % coins[0] == 0)  return t[i][amount] = amount/coins[0];
            
            return t[i][amount] =  1e9;
        }
        
        if(t[i][amount] != -1 ) return t[i][amount] ;
        
        int not_take = helper(i-1,coins,amount);
        int take = INT_MAX ;
        if(coins[i]<=amount){
            take = 1 + helper(i , coins , amount - coins[i]);
        }
            
       return t[i][amount] = min(take,not_take);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int cnt = 0;
        int n = coins.size();
        int ans = helper(n-1,coins,amount);
        if(ans == 1e9)  return -1;
        return ans;
    }
};