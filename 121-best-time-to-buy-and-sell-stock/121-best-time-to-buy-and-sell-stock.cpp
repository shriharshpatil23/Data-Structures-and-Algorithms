class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minSofar = prices[0];
        for(int i=1;i<prices.size();i++){
            minSofar = min(minSofar,prices[i]);
            ans = max(ans,prices[i]-minSofar);
        }
        return ans;
    }
};