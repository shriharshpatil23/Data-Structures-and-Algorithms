class Solution {
public:
    vector<vector<int>> t;
    
    int helper(int i, int n, int j, vector<int> &nums, vector<int> &M){
        
        if (j == M.size()) return 0;
        if (t[i][j] != INT_MIN) return t[i][j];
        
        // Left Side
        int left = helper(i + 1, n, j + 1, nums, M) + (nums[i] * M[j]);
        
        // Right Side
        int right = helper(i, n, j + 1, nums, M) + (nums[(n - 1) - (j - i)] * M[j]);
        
        return t[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& M) {   
        int n = nums.size(), m = M.size();
        t.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return helper(0, n, 0, nums, M);
    }
};