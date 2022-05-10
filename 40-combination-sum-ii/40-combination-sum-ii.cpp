class Solution {
public:
   void solve(int index, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>comb){
       //base case 
       if(target == 0){
            ans.push_back(comb);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){ 
            // this is to check for duplicates
            if(i>index && candidates[i]==candidates[i-1]) continue; 
            if(candidates[i] > target) break;
            comb.push_back(candidates[i]);
        // update the index to current position
            solve(i+1, target-candidates[i], candidates, ans, comb); 
            //backtrack step
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(0, target, candidates, ans, comb);
        return ans;
    }
};