class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 = 0;
        int cnt2 = 0;
        int maj1 = INT_MAX;
        int maj2 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1)   cnt1++;
            else    if(nums[i]==maj2)   cnt2++;
            else    if(cnt1 ==0){
                maj1 = nums[i];
                cnt1 =1;
            }else   if(cnt2 == 0){
                maj2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(auto x : nums){
            if(x == maj1)   cnt1++;
            if(x == maj2)   cnt2++;
        }
        if(cnt1 > nums.size()/3)  ans.push_back(maj1);
        if(cnt2 > nums.size()/3)   ans.push_back(maj2);
        
        return ans;
    }
};