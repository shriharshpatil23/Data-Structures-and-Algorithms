class Solution {
public:
    int countSubstrings(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int ans = 0;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int differ = 0;
                for(int k = 0; i+k<n1 && j+k<n2;k++){
                    if(s[i+k]!=t[j+k] && ++differ>1)  
                        break;
                    ans += differ;
                }
            }
        }
        return ans;
    }
};
