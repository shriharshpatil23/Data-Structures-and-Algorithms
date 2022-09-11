class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque <int> dq; //only indexes are stored
        for(int i=0;i<n;i++)
        {   
            while(!dq.empty() && i-dq.front()>=k)
                dq.pop_front(); //only window size of k is allowed
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]); //our max value in O(1)
        }
        return ans;
    }
};