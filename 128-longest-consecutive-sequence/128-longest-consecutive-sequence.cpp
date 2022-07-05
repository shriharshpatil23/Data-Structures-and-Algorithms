class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            unordered_set<int> s;
            int ans = 0;
            for (auto x: nums) s.insert(x);

            for (int i = 0; i < nums.size(); i++)
            {
                if (s.find(nums[i] - 1) != s.end())
                    continue;

                else
                {
                    int count = 0;
                    int current_element = nums[i];

                    while (s.find(current_element) != s.end())
                    {
                        count++;
                        current_element++;
                    }

                    ans = max(ans, count);
                }
            }

            return ans;
        }
};