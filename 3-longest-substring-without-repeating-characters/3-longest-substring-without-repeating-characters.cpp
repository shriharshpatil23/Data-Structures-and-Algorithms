class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_set<char> freq;
            freq.insert(s[i]);
            int len = 1;
            for(int j=i+1;j<n;j++){
                if(freq.find(s[j])==freq.end()){
                    len++;
                    freq.insert(s[j]);
                }else   break;
            }
            ans = max(ans,len);
        }
        return ans;
    }
};