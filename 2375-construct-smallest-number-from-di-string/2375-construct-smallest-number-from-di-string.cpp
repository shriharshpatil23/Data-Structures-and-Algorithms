class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        for (int i = 0, j = 0; i <= pattern.size(); ++i) {
            res.push_back('1' + i);
            if (i == pattern.size() || pattern[i] == 'I') {
                reverse(begin(res) + j, end(res));
                j = i + 1;
            }
        }
        return res;
    }
};