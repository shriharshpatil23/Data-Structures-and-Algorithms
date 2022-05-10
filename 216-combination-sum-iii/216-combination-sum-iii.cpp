class Solution {
public:
    void helper(int i , int target, int k ,vector<int> combinations,vector<int> comb,vector<vector<int>> &ans){
        //base case
        if(i==combinations.size() || k ==0){
            if(target==0 && k==0)   ans.push_back(comb);
            
            return;
        }
        //if you choose to add the element in comb
        if(combinations[i]<=target){
            comb.push_back(combinations[i]);
            int x = combinations[i];
            helper(i+1,target-x,k-1,combinations,comb,ans);
            comb.pop_back();
        }
        //if we want to skip the element
        helper(i+1,target,k,combinations,comb,ans);
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> combinations = {1,2,3,4,5,6,7,8,9};
        vector<int> comb;
        vector<vector<int>> ans;
        helper(0,target,k,combinations,comb,ans);
        return ans;
    }
};