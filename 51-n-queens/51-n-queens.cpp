class Solution {
public:
//     bool isSafe(int r, int c ,vector<string> &board, int n ){
//         int dr= r;
//         int dc= c;
        
//         //checking for diagonal in North-West direction
//         while(r>= 0 && c>=0){
//             if(board[r][c]=='Q')    return false;
            
//             r--;
//             c--;
//         }
        
//         r = dr;
//         c = dc;
        
//         //checking towards west direction
//         while(c>=0){
//             if(board[r][c]=='Q')    return false;
            
//             c--;
//         }
        
//         r = dr;
//         c = dc;
        
//         //checking towards south-west direction
//         while(r<n && c>=0){
//             if(board[r][c]=='Q')    return false;
            
//             r++;
//             c--;
//         }
        
//         return true;
//     }
    
    
//     void helper(int col, vector<string> &board,vector<vector<string>> &ans, int n){
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
        
//         for(int i=0;i<n;i++){                   //Trying for each cell in a Column
//             if(isSafe(i,col,board,n)){          // If after placing its safe then move to next column
//                 board[i][col] = 'Q';
//                 helper(col+1,board,ans,n);
//                 board[i][col]='.';              //Backtracking step
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i]=s;
//         }
//         helper(0,board,ans,n);
//         return ans;
    
    
    // By Hashing
    
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n, vector<int>& lR, vector<int>& upDg, vector<int>& lwDg){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(lR[row] == 0 && lwDg[row+col] == 0 && upDg[n-1+col-row] == 0){
                board[row][col] = 'Q';
                lR[row] = 1;
                lwDg[row+col] = 1;
                upDg[n-1+col-row] = 1;
                solve(col+1, ans, board, n, lR, upDg, lwDg);
                board[row][col] = '.';
                lR[row] = 0;
                lwDg[row+col] = 0;
                upDg[n-1+col-row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upDg(2*n - 1, 0), lwDg(2*n - 1, 0);
        solve(0, ans, board, n, leftRow, upDg, lwDg);
        return ans;
    
    }
};