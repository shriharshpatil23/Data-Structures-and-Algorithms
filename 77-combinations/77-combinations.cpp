class Solution {
public:
    void helper(int start, int n, int k , vector<vector<int>>&ans,vector<int>&tmp,int sz){
        if(sz==k){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=start+1;i<=n;i++){
            tmp.push_back(i);
            helper(i,n,k,ans,tmp,sz+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(0,n,k,ans,tmp,0);
        return ans;
    }
};