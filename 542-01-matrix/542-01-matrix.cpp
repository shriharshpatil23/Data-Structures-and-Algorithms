class Solution {
public:
    int m , n;
    bool isValid(int i, int j){
        if(i<0 || i>=m || j<0 || j>=n)  return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int inf = m + n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0){
                    int up = inf, left = inf;
                    if(isValid(i-1,j))  up = mat[i-1][j];
                    if(isValid(i,j-1))  left = mat[i][j-1];
                    mat[i][j] = 1 + min(up,left);
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]!=0){
                    int down = inf, right =inf;
                    if(isValid(i+1,j))  down = mat[i+1][j];
                    if(isValid(i,j+1))  right = mat[i][j+1];
                    mat[i][j] = min(mat[i][j] , min(down,right)+1);
                 }
            }
        }
        return mat;
    }
};