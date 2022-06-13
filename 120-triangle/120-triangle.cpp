class Solution {
public:
    int t[201][201];
    int helper(int i, int j, vector<vector<int>>& triangle){
        if(i==triangle.size()-1)    return triangle[i][j];
        
        if(i>triangle.size() || j > i)  return INT_MAX;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        int down = triangle[i][j] + helper(i+1,j,triangle);
        int cross = triangle[i][j] + helper(i+1,j+1,triangle);
        return t[i][j]=min(down,cross);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(t,-1,sizeof(t));
        return helper(0,0,triangle);
    }
};