class Solution {
public:
    
    bool vis[301];
   void dfs(vector<vector<int>>&isConnected,  int source){

		vis[source] = true;

		for(int i = 0; i < isConnected[source].size(); i++)
		{
			if(isConnected[source][i] && !vis[i])
				dfs(isConnected, i);
		}
	}

	int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
		int count = 0;
	//	vector<bool> vis(isConnected.size(), false);
        memset(vis,false,sizeof(vis));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(isConnected[i][j] && !vis[i])
				{
					dfs(isConnected, j);
					count++;
				}       
			}    
		}
		return count;
    }
};