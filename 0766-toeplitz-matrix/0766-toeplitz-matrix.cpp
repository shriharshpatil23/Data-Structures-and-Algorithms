class Solution {
public:
    bool helper(int i,int j,vector<vector<int>>mat){
        int tmp = mat[i][j];
        int x = i;
        int y = j;
        int m = mat.size();
        int n = mat[0].size();
        while(x<m && y<n){
            if(mat[x][y]!=tmp)  return false;
            x++;
            y++;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};