class cmp{
    public :
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first == b.first)  return a.second < b.second;
    
            return a.first > b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto str : words)   m[str]++;
        
        priority_queue<pair<int,string> ,vector<pair<int,string>> , cmp> pq;
        
        for(auto x : m){
            pq.push({x.second,x.first});
            
            if(pq.size()>k) pq.pop();
        }
        vector<string > ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};