class Solution {
public:
    int t[101][101];
    
    int Paths(int i ,int j, int x , int y){
        if(i>=x || j>=y)    return 0;
        if(i==x-1 && j==y-1)    return 1;
        if(t[i][j]!=-1) return t[i][j];
        
        return t[i][j] = Paths(i+1,j,x,y)+Paths(i,j+1,x,y);
    } 
    
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return Paths(0,0,m,n);
    }
};