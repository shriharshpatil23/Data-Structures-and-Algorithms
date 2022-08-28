class Solution {
public:
    int m ,n;
    void helper(int i, int j, vector<vector<int>> &mat){
        int x = i, y = j;
        vector<int> tmp;
        while(x<m && y<n)   tmp.push_back(mat[x++][y++]);
        sort(begin(tmp),end(tmp));
        for(auto x : tmp)   mat[i++][j++]=x;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        for(int i=0;i<m;i++){
            helper(i,0,mat);
        }
        for(int i=0;i<n;i++){
            helper(0,i,mat);
        }
        return mat;
    }
};