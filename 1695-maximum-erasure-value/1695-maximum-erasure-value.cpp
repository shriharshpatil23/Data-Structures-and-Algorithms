class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int currSum = 0;
        unordered_set<int> s;
        int start = 0;
        int i =0;
        while(i<nums.size()){
            int currEle = nums[i];
            if(s.find(currEle)==s.end()){
                currSum += currEle;
                ans = max(ans,currSum);
                s.insert(currEle);
                i++;
            }else{
                int del = nums[start];
                currSum -= del;
                s.erase(del);
                start++;
                
            }
        }
        return ans;
    }
};