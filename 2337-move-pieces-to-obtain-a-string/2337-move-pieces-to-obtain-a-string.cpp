class Solution {
public:
    bool canChange(string start, string target) {
            vector<pair<char, int>> v;
        
        for(int i=0; i<start.size(); i++){
            if(start[i] != '_'){
                v.push_back({start[i], i});
            }
        }
        
        int i=0;
        for(int j=0; j<target.size(); j++){
            if(target[j] != '_'){
                if(i>=v.size() || v[i].first != target[j]){
                    return false;
                }
                
                if(v[i].first == 'L' && v[i].second < j){
                    return false;
                }
                
                if(v[i].first == 'R' && v[i].second > j){
                    return false;
                }
                
                i++;
            }
        }
        
        return i == v.size();
    }
};