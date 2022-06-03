class NumMatrix
{
    public:
        NumMatrix(vector<vector < int>> &matrix)
        {
            ans = matrix;
            for (int i = 0; i < matrix.size(); ++i)
                for (int j = 0; j < matrix[0].size(); ++j)
                    ans[i][j] += a(i - 1, j) + a(i, j - 1) - a(i - 1, j - 1);
        }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return a(row2, col2) - a(row1 - 1, col2) - a(row2, col1 - 1) + a(row1 - 1, col1 - 1);
    }

    private:
        vector<vector < int>> ans;
    int a(int i, int j)
    {
        return i >= 0 && j >= 0 ? ans[i][j] : 0;
    }
};

/**
 *Your NumMatrix object will be instantiated and called as such:
 *NumMatrix* obj = new NumMatrix(matrix);
 *int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */