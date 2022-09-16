#define ll long long
class Solution {
public:
    ll helper(int start, int end, vector<int>&nums,int player){
        if(start>end)  return 0;
        
        if(player){
            ll play_1_left = nums[start] + helper(start+1,end,nums,0);
            ll play_1_right = nums[end] + helper(start,end-1,nums,0);
            return max(play_1_left,play_1_right);
        }else{
            ll play_2_left = -nums[start] + helper(start+1,end,nums,1);
            ll play_2_right = -nums[end] + helper(start,end-1,nums,1);
            return min(play_2_left,play_2_right);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(0,nums.size()-1,nums,1)>=0;
    }
};