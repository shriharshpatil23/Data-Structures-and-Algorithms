class Solution {
public:
    void helper(int i, int n, vector<int>&tmp,vector<vector<int>>&ans,vector<int>& nums){
        if(i==n){
            ans.push_back(tmp);
            return ;
        }
       helper(i+1,n,tmp,ans,nums);
        
        tmp.push_back(nums[i]);
        helper(i+1,n,tmp,ans,nums);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        helper(0,nums.size(),tmp,ans,nums);
        return ans;
    }
};