class Solution {
public:
    //This Dp is just same as Buy Sell Stocks DP !!!!!! Observe Carefully
    
    int t[1001][2][1001];
        int helper(int i, int high ,int prev,vector<int>& nums ){ //high 1 , 0 low
        if(i==nums.size())return 0; 
        if(t[i][high][prev] != -1)return t[i][high][prev];
        
        if(high){ //looking for high
            if(nums[i] > prev)return t[i][high][prev] = max(1 + helper(i+1, 0, nums[i],nums) , helper(i+1,1,prev,nums) ) ;
            else return t[i][high][prev] = helper(i+1,1,prev, nums);
        }
        
        else{ //looking for low
             if(nums[i] < prev)return t[i][high][prev] =  max(1+helper(i+1,1,nums[i] , nums) , helper(i+1,0,prev,nums));
            else return t[i][high][prev] = helper(i+1,0,prev ,nums);
            
        }
        
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return max( helper(1,1,nums[0] ,nums) , helper(1,0,nums[0] ,nums) ) +1;
    }
    
};