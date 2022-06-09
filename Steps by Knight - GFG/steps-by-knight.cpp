// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    bool vis[1001][1001];
    int N;
    bool isValid(int x, int y ){
        if(x<0 || x>=N || y<0 || y>=N || vis[x][y]==true)   return false;
        
        return true;
    }
    
    void BFS(int srcX,int srcY, int targetX, int targetY, vector<vector<int>> &cnt, int dx[], int dy[]){
        queue<pair<int,int>> q;
        q.push({srcX,srcY});
        vis[srcX][srcY]==true;
        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                if(isValid(currX + dx[i] , currY + dy[i])){
                    int newX = currX + dx[i];
                    int newY = currY + dy[i];
                    cnt[newX][newY] =  1 + cnt[currX][currY];
                    if(newY==targetY && newX==targetX)  return;
                    
                    vis[newX][newY]=true;
                    q.push({newX,newY});
                    
                }
            }
        }
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	     queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<int>> dist(N+1,vector<int>(N+1,0));
	    int dx[] = {-1,-2,-2,-1,1,1,2,2};
	    int dy[] = {-2,-1,1,2,-2,2,-1,1};
	    while(!q.empty()){
	        int size=q.size();
	        for(int c=0;c<size;c++){
	            auto temp = q.front();
	            q.pop();
	            if(temp.first==TargetPos[0] && temp.second==TargetPos[1])
	                return dist[temp.first][temp.second];
	            for(int k=0;k<8;k++)     {
	                int i = temp.first+dx[k];
	                int j= temp.second+dy[k];
	                if(i>0 && i<=N && j>0 && j<=N && dist[i][j]==0){
	                    dist[i][j]=dist[temp.first][temp.second]+1;
	                    q.push({i,j});
	                }
	            }
	                
	        }
	    }
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends