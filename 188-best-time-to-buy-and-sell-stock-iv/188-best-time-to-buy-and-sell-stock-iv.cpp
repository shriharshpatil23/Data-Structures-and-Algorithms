class Solution {
public:
    int t[1001][101][3];
    int helper(int buy, int i, int k, vector<int>&prices){
        if(k==0 || i==prices.size())    return 0;
        if(t[i][k][buy] !=-1)   return t[i][k][buy];
        int by = INT_MIN,sell=INT_MIN;
        if(buy==1){
            by = max(-prices[i] + helper(0,i+1,k,prices),helper(buy,i+1,k,prices));
        }else{
            sell = max(prices[i] + helper(1,i+1,k-1,prices),helper(0,i+1,k,prices));
        }
        return t[i][k][buy]=max(by,sell);
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return helper(1,0,k,prices);
    }
};