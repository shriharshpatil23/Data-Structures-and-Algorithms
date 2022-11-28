class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>  m_loser;
        set<int> winner;
        for(int i=0;i<matches.size();i++){
            m_loser[matches[i][1]]++;
        }
        for(int i=0;i<matches.size();i++){
            winner.insert(matches[i][0]);
        }
        vector<int> win;
        vector<int> loose;
        for(auto x : m_loser){
            if(x.second == 1){
                loose.push_back(x.first);
            }
        }
        for(auto x : winner){
            if(m_loser.find(x)==m_loser.end()){
                win.push_back(x);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(win);
        ans.push_back(loose);
        return ans;
    }
};