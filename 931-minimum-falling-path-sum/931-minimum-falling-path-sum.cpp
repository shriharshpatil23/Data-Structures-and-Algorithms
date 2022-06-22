class Solution {
public:
    int t[101][101];
    
    bool isValid(int i, int j , int n){
        if(i>=0 && i<n && j>=0 && j<n)  return true;
        
        return false;
    }
    
    int helper(int i ,int j ,  int n , vector<vector<int>> &m){
        if(!isValid(i,j,n)) return INT_MAX -101;
        
        if(i==n-1){
            return t[i][j] = m[n-1][j];
        }
        if(t[i][j]!= -1)    return t[i][j];
        //left 
        int left = m[i][j] + helper(i+1,j-1,n,m);
        //down
        int down = m[i][j] + helper(i+1,j,n,m);
        //right
        int right = m[i][j] + helper(i+1,j+1,n,m);
        
        return t[i][j] = min({left,right,down});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(t,-1,sizeof(t));
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            ;
            ans = min ( ans , helper(0,i,n,matrix));
        }
        return ans;
    }
};