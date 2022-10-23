class Solution
{
    public:
        long long makeSimilar(vector<int> &n, vector<int> &t)
        {
            sort(begin(n), end(n));
            sort(begin(t), end(t));
            long long res = 0;
            for (int i = 0, j1 = 0, j2 = 0; i < n.size(); ++i)
            {
                int &j = n[i] % 2 ? j1 : j2;
                while (n[i] % 2 != t[j] % 2)
                    ++j;
                res += abs(n[i] - t[j]) / 2;
                ++j;
            }
            return res / 2;
        }
};