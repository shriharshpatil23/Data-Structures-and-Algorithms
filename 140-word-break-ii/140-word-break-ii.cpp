class Solution {
public:
    unordered_set<string> st;
    void helper(int i, string s, vector<string>&wordDict, vector<string> &ans, string tmp){
        if(i==s.size()){
            tmp.pop_back();
            ans.push_back(tmp);
            return;
        }
        string t ="";
        for(int j=i;j<s.size();j++){
            t = t + s[j];
            if(st.find(t)!=st.end()){
                tmp = tmp + t + " ";
                helper(j+1,s,wordDict,ans,tmp);
                int len = t.size() + 1;
                while(len--){
                    tmp.pop_back();
                }
            }
        }    
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        for(auto x : wordDict)  st.insert(x);
                
        helper(0,s,wordDict,ans,"");
        return ans;
    }
};