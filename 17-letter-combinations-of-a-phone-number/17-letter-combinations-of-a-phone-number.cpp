class Solution {
public:
    string m[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};    

    void helper(string digits,string op,int i,vector<string> &ans){
        if(i>=digits.size()){
            ans.push_back(op);
            return;
        }
        int n = digits[i]-'0';
        string val = m[n-1];
        
        for(int j=0;j<val.size();j++){
            op.push_back(val[j]);
            helper(digits,op,i+1,ans);
            //backtracking Step
            op.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size()==0)    return ans;
        
        string op ="";
        int i = 0;
       // vector<string> m = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        helper(digits,op,i,ans);
        return ans;
    }
};