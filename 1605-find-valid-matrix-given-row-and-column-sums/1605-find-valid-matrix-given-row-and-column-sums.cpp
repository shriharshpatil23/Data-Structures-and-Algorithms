class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        int m = rs.size();
        int n = cs.size();
        vector<vector<int>> ans(m,vector<int> (n));
        for (int x = 0; x < m; ++x)
        for (int y = 0; y < n && rs[x] > 0; ++y) {
            ans[x][y] = min(rs[x], cs[y]);
            rs[x] -= ans[x][y];
            cs[y] -= ans[x][y];
        }
        return ans;
    }
};