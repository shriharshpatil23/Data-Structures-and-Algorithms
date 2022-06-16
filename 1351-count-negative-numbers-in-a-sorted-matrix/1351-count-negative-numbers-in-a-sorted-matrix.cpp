class Solution {
public:
    int helper(vector<int> nums){
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start<=end){
            mid = start + (end - start)/2;
            if(nums[mid]>=0){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return nums.size() - end - 1;
    }
    
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            ans += helper(grid[i]);
        }
        return ans;
    }
};