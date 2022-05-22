class Solution {
public:
    int t[1001][1001];
    int helper(string s , int i , int j){
        if(i>=j)    return 1;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        if(s[i]!=s[j])  return 0;
        
        return t[i][j] = helper(s,i+1,j-1);
    }
    
    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int len = s.size();
        int ans = 0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(helper(s,i,j))   ans++;
            }
        }
        return ans;
    }
};