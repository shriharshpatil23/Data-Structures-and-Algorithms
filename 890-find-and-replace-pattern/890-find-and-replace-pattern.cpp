class Solution {
public:
    vector<int> patternMatch(string s){
        vector<int> ans;
        map<char,int> mp;
        int ch = 1;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                ans.push_back(ch);
                mp[s[i]]=ch;
                ch++;
            }else{
                ans.push_back(mp[s[i]]);
            }
        }
        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<int> pp = patternMatch(pattern);
        for(auto x : words){
            vector<int> tmp = patternMatch(x);
            if(tmp==pp) ans.push_back(x);
        }
        return ans;
    }
};