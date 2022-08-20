class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int> row_max(n), column_max(n);
        for(int i=0;i<n;i++){
            int tmp = INT_MIN;
            for(int j=0;j<n;j++){
                tmp = max(tmp,grid[i][j]);
            }
            row_max[i]=tmp;
        }
        for(int j=0;j<n;j++){
            int tmp = INT_MIN;
            for(int i=0;i<n;i++){
                tmp = max(tmp, grid[i][j]);
            }
            column_max[j]=tmp;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tmp = min(row_max[i],column_max[j]);
                ans += tmp - grid[i][j];
            }
        }
        return ans;
    }
};
