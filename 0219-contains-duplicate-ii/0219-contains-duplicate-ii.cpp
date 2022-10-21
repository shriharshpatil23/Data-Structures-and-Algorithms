class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,set<int>> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                set<int> st = mp[nums[i]];
                for(auto x : st){
                    if(abs(i-x)<=k) return true;
                }
            }
            mp[nums[i]].insert(i);
        }
        return false;
    }
};