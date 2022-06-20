class Solution {
public:
   bool nextPermutation(string& s) {
        int n = s.size();
        int idx = -1;
        
        for (int i = n - 1; i > 0; i--) {
            if (s[i - 1] < s[i]) {
                idx = i;
                break;
            }    
        }
        
        if (idx == -1) {
            return false;
        } else {
            int prev = idx;
            
            for (int i = idx + 1; i < n; i++) {
                if (s[i] > s[idx - 1] && s[i] <= s[prev]) {
                    prev = i;
                }
            }
            
            swap(s[idx - 1], s[prev]);
            reverse(s.begin() + idx, s.end());
            
            return true;
        }
    }
    
    int nextGreaterElement(int n) {
        string num = to_string(n);
        bool res = nextPermutation(num);
        size_t ans = stoll(num);
        return (!res || ans > INT_MAX) ? -1 : ans;
    }
};