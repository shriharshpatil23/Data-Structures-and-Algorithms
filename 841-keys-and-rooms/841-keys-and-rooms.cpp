class Solution {
public:
    void dfs(int node , vector<vector<int>>&rooms, vector<bool> &vis){
        vis[node]= true;
        for(auto x : rooms[node]){
            if(!vis[x]){
                dfs(x,rooms,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        for(auto x : vis){
            if(x==false)    return false;
        }
        return true;
    }
};