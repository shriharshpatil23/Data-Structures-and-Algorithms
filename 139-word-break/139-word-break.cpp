class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int helper(int i, string s, vector<string> &wordDict){
        if(i==s.size()) return 1;
        
        if(t[i]!= -1)   return t[i];
        
        string tmp ="";
        for(int j=i;j<s.size();j++){
            tmp = tmp + s[j];
            if(st.find(tmp)!=st.end()){
                if( helper(j+1,s,wordDict)) return t[i]=1;
            }
        }
        return t[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict){
            st.insert(x);
        }
        memset(t,-1,sizeof(t));
        return helper(0,s,wordDict);
    }
};