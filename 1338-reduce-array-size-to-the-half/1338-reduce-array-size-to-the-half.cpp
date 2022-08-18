class Solution {
public:    
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        priority_queue<int> q;
        for(auto x : m){
            q.push(x.second);
        }
        int moves = 0;
        int reduced = 0;
        while(reduced < n/2){
            reduced += q.top();
            q.pop();
            moves++;
        }
        return moves;
    }
};