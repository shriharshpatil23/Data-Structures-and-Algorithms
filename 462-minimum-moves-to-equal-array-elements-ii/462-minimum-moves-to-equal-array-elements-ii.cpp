class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums[(nums.size()-1)/2];
        int moves = 0;
        for(int i=0;i<nums.size();i++){
            moves += abs(nums[i]-mid);
        }
        return moves;
    }
};