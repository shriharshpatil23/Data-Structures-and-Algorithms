class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        for(auto x : s) mp[x]++;
        for(auto x : t) mp[x]--;
        int ans = 0;
        for(auto x : mp){
            ans += abs(x.second);
        }
        return ans;
    }
};