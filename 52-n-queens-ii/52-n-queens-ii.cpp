class Solution {
public:
    bool isSafe(int r, int c ,vector<string> &board, int n ){
        int dr= r;
        int dc= c;
        
        //checking for diagonal in North-West direction
        while(r>= 0 && c>=0){
            if(board[r][c]=='Q')    return false;
            
            r--;
            c--;
        }
        
        r = dr;
        c = dc;
        
        //checking towards west direction
        while(c>=0){
            if(board[r][c]=='Q')    return false;
            
            c--;
        }
        
        r = dr;
        c = dc;
        
        //checking towards south-west direction
        while(r<n && c>=0){
            if(board[r][c]=='Q')    return false;
            
            r++;
            c--;
        }
        
        return true;
    }
    
    
    void helper(int col, vector<string> &board,int &ans, int n){
        if(col==n){
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++){                   //Trying for each cell in a Column
            if(isSafe(i,col,board,n)){          // If after placing its safe then move to next column
                board[i][col] = 'Q';
                helper(col+1,board,ans,n);
                board[i][col]='.';              //Backtracking step
            }
        }
    }
    
    int totalNQueens(int n) {
        //vector<vector<string>> ans;
        int ans = 0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(0,board,ans,n);
        return ans;
    }
};