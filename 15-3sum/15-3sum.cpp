class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int target = 0 - nums[i];
            int start = i+1;
            int end = n-1;
            int mid ;
            while(start < end){
                if(nums[start]+nums[end]==target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start ++ ;
                    end--;
                }else   if(nums[start]+nums[end] > target)  end--;
                else    start++;
            }
        }
        set<vector<int>> s(ans.begin(),ans.end());
        vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};