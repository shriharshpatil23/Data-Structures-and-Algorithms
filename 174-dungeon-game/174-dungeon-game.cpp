class Solution {
public:
    int t[1001][1001];
    
    int helper(int i,int j, vector<vector<int>>& dungeon,int m ,int n){
        if(i>=m || j>=n)  return INT_MIN;
        
        if(t[i][j]!= -1 )   return t[i][j];
        
        
        if(i==m-1 && j==n-1)    return min(0,dungeon[i][j]);
       
        
        return t[i][j]=min(0,max(helper(i,j+1,dungeon,m,n),helper(i+1,j,dungeon,m,n))+dungeon[i][j]);
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(t,-1,sizeof(t));
        int m = dungeon.size();
        int n = dungeon[0].size();
        int ans = abs(helper(0,0,dungeon,m,n));
        return ans + 1;
    }
};