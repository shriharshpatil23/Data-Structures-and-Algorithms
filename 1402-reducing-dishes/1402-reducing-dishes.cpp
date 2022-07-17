class Solution {
public:
    int t[501][501];
    int helper(int i, int time, vector<int> &satisfaction,vector<vector<int>>&t){
        if(i==satisfaction.size())  return t[i][time] = 0;
        
        if(t[i][time]!= -1) return t[i][time];
        
        int take = satisfaction[i]*(time) + helper(i+1,time+1,satisfaction,t);
        int not_take = 0 + helper(i+1,time,satisfaction,t);
        
        return t[i][time] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>>t(501,vector<int>(501,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return helper(0,1,satisfaction,t);
    }
};