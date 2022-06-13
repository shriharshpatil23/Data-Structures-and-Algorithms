class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int prev = values[0] + 0;
        for(int i=1;i<values.size();i++){
            ans = max(ans , values[i]-i + prev);
            prev = max(prev, values[i]+i);
        }
        return ans;
    }
};