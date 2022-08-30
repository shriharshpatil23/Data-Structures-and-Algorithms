class Solution {
public:
    vector<int> og;
    Solution(vector<int>& nums) {
        og = nums;
    }
    
    vector<int> reset() {
        return og;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = og;
        
        for (int i = og.size() - 1; i >= 0; i--) {
            int r = rand() % (i+1);
            swap(shuffled[i], shuffled[r]);
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */