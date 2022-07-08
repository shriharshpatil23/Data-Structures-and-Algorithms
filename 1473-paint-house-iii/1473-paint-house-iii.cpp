class Solution {
public:
       int dp[100][100][21];
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int target, int ind,int neiCnt, int prev) {
        if (ind == houses.size()) {
           
            if(neiCnt == target)
                return 0;
            
            return 1e7;
        }
        
        if (neiCnt > target) {
            return 1e7;
        }
     
        if (dp[ind][neiCnt][prev] != -1) {
            return dp[ind][neiCnt][prev];
        }
        
        int minCost = 1e7;
        if (houses[ind]) {
            int newNeighborhoodCount = neiCnt + (houses[ind] != prev);
            minCost = 
                findMinCost(houses, cost, target, ind + 1, newNeighborhoodCount, houses[ind]);
        } else {
            int totalColors = cost[0].size();
            
            for (int color = 1; color <= totalColors; color++) {
                int newNeighborhoodCount = neiCnt + (color != prev);
                int currCost = cost[ind][color - 1]
                    + findMinCost(houses, cost, target, ind + 1, newNeighborhoodCount, color);
                minCost = min(minCost, currCost);
            }
        }
        return dp[ind][neiCnt][prev] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp, -1, sizeof(dp));
        int ans = findMinCost(houses, cost, target, 0, 0, 0);
        
        if(ans>=1e7)
            return -1;
        return ans;
    }
};