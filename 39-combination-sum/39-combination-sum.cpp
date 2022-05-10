class Solution {
public:
    void helper(int i , vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> comb){
        //base Case
        if(i==candidates.size()){
            if(target==0)   ans.push_back(comb);
            
            return;
        }
        //if you wish to take the element at index i
        if(candidates[i]<=target){
            comb.push_back(candidates[i]);
            helper(i,candidates,target-candidates[i],ans,comb);
            //backtrack step
            comb.pop_back();
        }
        //if you dont want to take the element at index i
        helper(i+1,candidates,target,ans,comb);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(0,candidates,target,ans,comb);
        return ans;
    }
};