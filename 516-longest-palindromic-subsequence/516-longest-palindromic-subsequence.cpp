class Solution {
public:
    int t[1001][1001];
    int lcs(int i, int j, string &s){
        if(i==j)    return t[i][j]=1;
        
        if(i>j)    return 0;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        if(s[i]==s[j]) return t[i][j] = 2 + lcs(i+1,j-1,s);
        else{
            return t[i][j] = max(lcs(i+1,j,s),lcs(i,j-1,s));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return lcs(0,n-1,s);
    }
};