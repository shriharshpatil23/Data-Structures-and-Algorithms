class Solution {
public:
//     int m , n;
//   //  int t[501][501][501][501];
//     int helper(int i , int j , string word1, int x, int y, string word2){
//         if(i>= m || j<0 || i>j || x>=n || y<0 || x>y )  return 0;
//         if(word1.substr(i,j)==word2.substr(x,y))    return 1;
        
//       //  if(t[i][j][x][y]!= -1)  return t[i][j][x][y];
        
//         int w1 = helper(i+1,j,word1,x,y,word2);
//         int w2 = helper(i,j-1,word1,x,y,word2);
//         int w3 = helper(i,j,word1,x+1,y,word2);
//         int w4 = helper(i,j,word1,x,y-1,word2);
        
//         return  1 + min({w1,w2,w3,w4});
        
//     }
    
//     int minDistance(string word1, string word2) {
//         m = word1.size();
//         n = word2.size();
//      //   memset(t,-1,sizeof(t));
//         return helper(0,m-1,word1,0,n-1,word2);
    int t[501][501];
    
    int LCS(int i , int j , string word1, string word2){
        if(i==0 || j==0)    return 0;
        
        if(t[i][j] != -1)   return t[i][j];
        
        if(word1[i-1]==word2[j-1]){
            return t[i][j] = 1 + LCS(i-1,j-1,word1,word2);
        }
        return t[i][j] = max(LCS(i-1,j,word1,word2), LCS(i,j-1,word1,word2));
    }
    
     int minDistance(string word1, string word2) {
         int m = word1.size();
         int n = word2.size();
         memset(t,-1,sizeof(t));
         int lcs = LCS(m,n,word1,word2);
         return m - lcs + n - lcs;
    }
};