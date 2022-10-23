class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int,int>mp;
        for(auto x : nums)  mp[x]++;
        
        int n = nums.size();
        for(int i=1;i<=n;i++){
            if(mp.find(i)!=mp.end() && mp[i]>=2){
                ans.push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end())    ans.push_back(i);
        }
        return ans;
    }
};