class Solution {
public:
    vector<string> keys {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void helper(int i, string tmp, vector<int> dig, vector<string> &ans){
        if(i==dig.size()){
            ans.push_back(tmp);
            return;
        }
        string val = keys[dig[i]];
        for(int k = 0; k<val.size();k++){
            tmp.push_back(val[k]);
            helper(i+1,tmp,dig,ans);
            tmp.pop_back();     //Backtraking step
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<int> dig;
        if(digits.size()==0)    return {};
        for(auto x : digits){
            int tmp = x - '0';
            dig.push_back(tmp);
        }
        vector<string> ans;
        helper(0,"",dig,ans);
        return ans;
    }
};