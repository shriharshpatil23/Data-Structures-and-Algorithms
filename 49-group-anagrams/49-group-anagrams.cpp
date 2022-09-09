class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char,int>,vector<string>> mp;
        for(auto x : strs){
            map<char,int> m;
            for(auto y : x) m[y]++;
            mp[m].push_back(x);
        }
        for(auto x : mp){
            ans.push_back(x.second);            
        }
        return ans;
    }
};