class Solution {
public:
    int t[301][301];
    
    int helper(int i,int j, vector<vector<char>>& matrix){
        if(i<0 || j<0  ) return   0;
        
        if(t[i][j]!=-1) return t[i][j];
        
        int up = helper(i-1,j,matrix);
        int left = helper(i,j-1,matrix);
        int diagonal = helper(i-1,j-1,matrix);
        
        if(matrix[i][j]=='1')   return t[i][j] = 1 + min(up,min(left,diagonal));
        else    return t[i][j]=0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        memset(t,-1,sizeof(t));
        int n = matrix[0].size();
        int ans = 0;
        helper(m-1,n-1,matrix);
        for(int i=0;i<301;i++){
            for(int j=0;j<301;j++){
                ans  = max(ans,t[i][j]);
            }
        }
        return ans*ans;
    }
};