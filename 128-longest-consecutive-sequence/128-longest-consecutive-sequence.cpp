class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto x : nums)  s.insert(x);
        int ans = 0;
        for(auto x : nums){
            if(s.find(x)==s.end())  continue;
            s.erase(x);
            int next = x+1;
            int prev = x-1;
            while(s.find(prev)!=s.end())    s.erase(prev--);
            while(s.find(next)!=s.end())    s.erase(next++);
            ans = max(ans, next - prev -1);
        }
        return ans;
    }
};