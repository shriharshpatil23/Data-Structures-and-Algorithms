class NumArray {
// Stores Binary Indexed Tree and original array 
    vector<int> bit, nums;
    int n = 0;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        // The parent node in BIT is dummy, so +1 the size
        bit.resize(n + 1, 0);
        // Build BIT by doing update operation for each index with the value
        for(int idx = 0; idx < nums.size(); idx++)
            updateBIT(idx + 1, nums[idx]);
    }
    
    // Makes the updates to applicable nodes. Delta is the net change
    // needed for each node.
    void updateBIT(int index, int delta) {
        // Propagate the delta downwards till within the array
        while(index < bit.size()) {
            // notice how only delta is added at each node and not replaced
            bit[index] += delta;
            // Go to next node by adding the last set bit number
            // (index & -index): Number created by right most set bit
            index = index + (index & -index);
        }    
    }
    
    void update(int index, int val) {
        // BIT works on 1 based indexing, convert to 1 based index
        ++index;
        // Find the delta change for the index value, this is done by comapring
        // the value at the original nums array
        updateBIT(index, val - nums[index-1]);
        // Set the value in original array, this will be 
        // useful next time when a delta is calculated
        nums[index-1] = val;
    }
    
    // Finds the prefix sum in nums[0:idx-1]
    int prefixSum(int idx) {
        int sum = 0;
        // Go upwards towards the root
        while(idx > 0) {
            sum += bit[idx];
            idx = idx - (idx & -idx);
        }    
        return sum;
    }
    
    int sumRange(int left, int right) {
        // convert to 1 based index
        ++left, ++right;
        // nums[right-1:left-1] = nums[right-1:0] - nums[left-1:0]
        return prefixSum(right) - prefixSum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */