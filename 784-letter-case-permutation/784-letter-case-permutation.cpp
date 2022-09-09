class Solution {
public:
    void helper(int i, string s, string &tmp, set<string>&st){
        if(i==s.size()){
            st.insert(tmp);
            return;
        }
        if(s[i]>='0' && s[i]<='9'){
            tmp.push_back(s[i]);
            helper(i+1,s,tmp,st);
            tmp.pop_back();
        }else{
            if(s[i]>='a' && s[i]<='z'){
                tmp.push_back(s[i]);
                helper(i+1,s,tmp,st);
                tmp.pop_back();
                
                tmp.push_back(toupper(s[i]));
                helper(i+1,s,tmp,st);
                tmp.pop_back();
            }
            
            if(s[i]>='A' && s[i]<='Z'){
                tmp.push_back(s[i]);
                helper(i+1,s,tmp,st);
                tmp.pop_back();
                
                tmp.push_back(tolower(s[i]));
                helper(i+1,s,tmp,st);
                tmp.pop_back();
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        set<string> st;
        string tmp ="";
        helper(0,s,tmp,st);
        vector<string> ans;
        for(auto x : st)    ans.push_back(x);
        return ans;
    }
};