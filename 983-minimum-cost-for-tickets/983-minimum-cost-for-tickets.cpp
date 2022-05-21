class Solution {
public:
    unordered_set<int> s;
    int t[366];
    int helper(int i , vector<int>& costs, vector<int>& days){
        if(i>days[days.size()-1])   return 0;
        
        if(t[i]!= -1 )  return t[i];
        
        int ans = 1e9;
        
        if(s.find(i)==s.end()){
            ans = helper(i+1,costs,days);
        }else{
            int d = helper(i+1,costs,days) + costs[0];
            int w = helper(i+7,costs,days) + costs[1];
            int m = helper(i+30,costs,days) + costs[2];
            ans = min({ans,d,w,m});
        }
        return t[i] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        for(auto x : days){
            s.insert(x);
        }
        return helper(days[0],costs,days);
    }
};