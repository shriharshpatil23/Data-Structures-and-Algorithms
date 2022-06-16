class Solution {
public:
    
    void helper(int i, vector<int> nums, vector<vector<int>> &ans, vector<int> tmp,set<vector<int>> &s){
        if(s.find(tmp)==s.end()){
            ans.push_back(tmp);
            s.insert(tmp);
        }
        
                   
        if(i>=nums.size())    return;
        for(int j=i;j<nums.size();j++){
           // if(j>i &&  nums[j]==nums[j-1]) continue;
            tmp.push_back(nums[j]);
            helper(j+1,nums,ans,tmp,s);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,{},s);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};