class Solution {
public:
    // vector<int> countSmaller(vector<int>& nums) {
    //     vector<int> ans;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         int cnt = 0;
    //         for(int j=i+1;j<n;j++){
    //             if(nums[j]<nums[i]) cnt++;
    //         }
    //         ans.push_back(cnt);
    //     }
    //     return ans;
     int BIT[1000000] = {};
    
    void update(int ind){
        for(;ind<1000000;ind += (ind&-ind)) BIT[ind]++;
    }
    
    int get(int ind){
        int sum = 0;
        ind--;
        for(;ind>0;ind -= (ind&-ind)) sum += BIT[ind];
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        for(int&i : nums) i += 10001;
        reverse(nums.begin(), nums.end());
        
        vector<int> ans(nums.size());
        
        for(int i=0;i<nums.size();i++){
            ans[i] = get(nums[i]);
            update(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};