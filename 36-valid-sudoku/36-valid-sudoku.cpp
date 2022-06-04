class Solution {
public:
    
//     bool isSafe(int row, int col , vector<vector<char>>& board, char c){
//         for(int i=0;i<9;i++){
//             if(board[i][col]==c)    return false;
            
//             if(board[row][i]==c)    return false;
            
//             if(board[3*(row/3) + i/3][3*(col/3) + i/3]==c)  return false;
            
//         }
            
//             return true;
        
//     }
    
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     for(int i=0;i<9;i++){
    //         for(int j=0;j<9;j++){
    //             if(board[i][j] != '.'){
    //                 if(isSafe(i, j , board , board[i][j])==false) return false;
    //             }
    //         }
    //     }
    //     return true;
     bool isValidSudoku(vector<vector<char>>& board) {
            vector<set<int>> rows(9), cols(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') continue;
                
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr)) 
                    return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
            }
        }
        
        return true;
    }
};