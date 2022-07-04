class Solution {
public:
//     int m;
//     int n;
//     int srx;
//     int sry;
//     bool isValid(int i, int j, int color, vector<vector<int>> image){
//         if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=image[srx][sry] || image[i][j]==color)  return false;
        
//         return true;
//     }
//     void bfs(int i , int j , int color, vector<vector<int>> &image){
//        // if(isValid(i,j,color,image)==false)   return;
//         queue<pair<int,int>> q;
//         q.push({i,j});
//         image[i][j]=color;
//         while(!q.empty()){
//             auto pr = q.front();
//             int x = pr.first;
//             int y = pr.second;
//             q.pop();
//             //up
//             if(isValid(x-1,y,color,image)){
//                 q.push({x-1,y});
//                 image[x-1][y]=color;
//             }
//             //down
//             if(isValid(x+1,y,color,image)){
//                 q.push({x+1,y});
//                 image[x+1][y]=color;
//             }
//             //right
//             if(isValid(x,y+1,color,image)){
//                 q.push({x,y+1});
//                 image[x][y+1]=color;
//             }
            
//             //left
//             if(isValid(x,y-1,color,image)){
//                 q.push({x,y-1});
//                 image[x][y-1]=color;
//             }
//         }
//     }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>qu;
        qu.push({sr, sc});
        
        vector<int>vis(image.size()*image[0].size(),0);
        vis[image[0].size()*sr + sc] = 1;
        int colorwanted = image[sr][sc];
        //up down left right
        vector<vector<int>>dir = {{-1,0},{+1,0},{0,-1},{0,+1}};
        
        while(qu.empty()==false){
            int currrow = qu.front().first;
            int currcol = qu.front().second;
            qu.pop();
            image[currrow][currcol] = color;

            
            for(int i = 0; i<4; i++){
                int x = currrow+dir[i][0];
                int y = currcol+dir[i][1];
                
                if(x>=0 and x<image.size() and y>=0 and y<image[0].size() and vis[image[0].size()*x +y] == 0 and image[x][y]==colorwanted){
                    vis[image[0].size()*x +y] = 1;
                    qu.push({currrow+dir[i][0],currcol+dir[i][1]});
                }
            }
            
        }
        
        return image;
    }
};