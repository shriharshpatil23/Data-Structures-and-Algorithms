class Solution {
public:
//     unordered_map<int, int> f;
//     int islands = 0;

//     int find(int x) {
//         if (!f.count(x)) f[x] = x, islands++;
//         if (x != f[x]) f[x] = find(f[x]);
//         return f[x];
//     }

//     void uni(int x, int y) {
//         x = find(x), y = find(y);
//         if (x != y) f[x] = y, islands--;
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         for (int i = 0; i < stones.size(); ++i)
//             uni(stones[i][0], ~stones[i][1]);
//         return stones.size() - islands;
//     }
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int i=0;i<n;i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }

};