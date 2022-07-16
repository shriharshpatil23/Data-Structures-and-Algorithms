class Solution {
public:
    long long mod = 1000000007;
    int t[51][51][51];
    long long solve(int i,int j, int moves, int m, int n)
    {
        if(moves<0) return 0;   // We ran out of moves
        
        if(i<0 || j<0 || i>=m || j>=n)  // We cross the boundary hence a valid answer.
        return 1;
        
        if(t[i][j][moves]!=-1)  // We have already evaluated for this state
        return t[i][j][moves];
        
        long long up = solve(i-1,j,moves-1,m,n);     //Moving up
        long long down = solve(i+1,j,moves-1,m,n);   //Moving Down
        long long right = solve(i,j+1,moves-1,m,n);  //Moving right
        long long left =  solve(i,j-1,moves-1,m,n);  //Moving Left
        
        return t[i][j][moves] = ((up%mod) + (down%mod) + (left%mod) + (right%mod))%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        return solve(startRow,startColumn,maxMove,m,n);
    }
};