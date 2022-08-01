class Solution {
public:
    bool isValid(string s){
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.empty())  return false;
                st.pop();
            }
        }
        if(st.empty())  return true;
        else    return false;
    }
    void helper(string s, int start, int end, unordered_set<string> &ans){
        if(start==end ){
            if(isValid(s))  ans.insert(s);
            
            return;
        }else{
            for(int i=start;i<=end;i++){
                swap(s[start],s[i]);
                helper(s,start+1,end,ans);
                swap(s[start],s[i]);
            }
        }
    }
    
    
    void generateParenthesis(int open, int close, string op, vector<string>& ans) {
        if(open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }
        
        if(open > 0) generateParenthesis(open-1, close, op+"(", ans);
        
        if(close > open) generateParenthesis(open, close-1, op+")", ans);
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        //!!!!!!!!!  Brute force!!!!!!!!!!!!!!!
        // string tmp = "";
        // unordered_set<string> ans;
        // vector<string> res;
        // for(int i=0;i<n;i++){
        //     tmp.push_back('(');
        // }
        // for(int i=0;i<n;i++){
        //     tmp.push_back(')');
        // }
        // int len = tmp.size()-1;
        // helper(tmp,0,len,ans);
        // for(auto x: ans)    res.push_back(x);
        // return res;
        
         vector<string> ans;
        int open = n;
        int close = n;
        string op = "";
        generateParenthesis(open, close, op, ans);
        
        return ans;      
        
    }
};















