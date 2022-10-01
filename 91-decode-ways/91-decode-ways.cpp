class Solution {
public:
    int dp[101];
    int helper(int i, string s){
        if(i==s.size())return 1;
        
        if(s[i]=='0')return 0;
        
        if(i>=s.size()-1)return 1;
        
        if(dp[i]!=-1)   return dp[i];
        
        string sub = s.substr(i,2);
        int ways1 = helper(i+1,s);
        int ways2 = 0;
        if(stoi(sub)>0 && stoi(sub)<=26){
            ways2=helper(i+2,s);
        }
        return dp[i]=ways1+ways2;
    }
    int numDecodings(string s) {
        if(s=="0")  return 0;
        memset(dp,-1,sizeof(dp));
        return helper(0,s);
    }
};