class Solution {
public:
    // [1,5,2,7,1] level first peak 5 in 3 decrements
    // [1,2,2,7,1] level second peak 7 in 5 decrements
    // [1,2,2,2,1] level 2 in 1 decrement
    // [1,1,1,1,1] level 1 in 1 decrement
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); ++i)
            ans += max(0, target[i] - target[i - 1]);
        return ans;
    }
};