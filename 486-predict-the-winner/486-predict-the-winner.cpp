#define ll long long
class Solution {
public:
    ll t[2][21][21];
    ll helper(int start, int end, vector<int>&nums,int player){
        if(start>end)  return 0;
        
        if(t[player][start][end]!=-1)   return t[player][start][end];
        
        if(player){
            ll play_1_left = nums[start] + helper(start+1,end,nums,0);
            ll play_1_right = nums[end] + helper(start,end-1,nums,0);
            return t[player][start][end] = max(play_1_left,play_1_right);
        }else{
            ll play_2_left = -nums[start] + helper(start+1,end,nums,1);
            ll play_2_right = -nums[end] + helper(start,end-1,nums,1);
            return t[player][start][end]=min(play_2_left,play_2_right);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,nums.size()-1,nums,1)>=0;
    }
};