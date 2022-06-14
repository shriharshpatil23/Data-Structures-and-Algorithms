class Solution {
public:
    int t[50001][3];
    int fees;
    
    int helper(int i, int buy , vector<int> &prices){
        if(i==prices.size())    return 0;
        
        if(t[i][buy] != -1) return t[i][buy];
        
        if(buy){
            return t[i][buy] = max(-prices[i] + helper(i+1,0,prices), helper(i+1,1,prices));
        }else{
            return t[i][buy] = max(prices[i] + helper(i+1,1,prices) - fees , helper(i+1,0,prices));
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        fees = fee;
        memset(t,-1,sizeof(t));
        return helper(0,1,prices);
    }
};