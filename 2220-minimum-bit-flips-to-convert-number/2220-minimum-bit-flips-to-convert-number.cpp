class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s = bitset<64> (start).to_string();
        string g = bitset<64> (goal).to_string();
        int ans = 0;
        for(int i=0;i<64;i++){
            if(s[i]!=g[i])  ans++;
        }
        return ans;
    }
};