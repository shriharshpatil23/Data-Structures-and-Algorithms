class Solution {
public:
     void helper(int i, vector<int> &nums,set<vector<int>> &ans){
        if(i==nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            helper(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        helper(0,nums,ans);
        vector<vector<int>> ans2;
        for(auto x : ans){
            ans2.push_back(x);
        }
        return ans2;
    }
};