class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int n = nums.size();
            int ans = INT_MIN;
            int x = 1;
            int y = 1;
            for (int i = 0; i < n; i++)
                {
                        x *= nums[i];
                        y *= nums[n - 1 - i];
                        ans = max(ans, max(x, y));
                        if (x == 0) x = 1;
                        if (y == 0) y = 1;
                }
            return ans;
      }
};