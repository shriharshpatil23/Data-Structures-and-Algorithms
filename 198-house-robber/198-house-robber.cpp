class Solution
{
    public:
        int t[101];
   
        int rec(vector<int> &nums, int idx)
        {
            if (idx >= nums.size()) return 0;
            if (t[idx] != -1) return t[idx];
            return t[idx] = max(rec(nums, idx + 1), nums[idx] + rec(nums, idx + 2));
        }
        int rob(vector<int> &nums)
        {
           memset(t,-1,sizeof(t));
            return rec(nums, 0);
        }
    };