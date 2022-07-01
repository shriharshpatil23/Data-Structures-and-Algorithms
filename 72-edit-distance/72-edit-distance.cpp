class Solution {
public:
    
          //TopDown + memoization 
    int t[501][501];
    int f(string& s1, string& s2, int i, int j){
        int n=s1.size(),m=s2.size();
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(t[i][j]!=-1) return t[i][j];
            
        if(s1[i]==s2[j])
            return t[i][j] = 0 + f(s1,s2,i+1,j+1);
        int rep = 1 + f(s1,s2,i+1,j+1);
        int ins = 1 + f(s1,s2,i+1,j);
        int del = 1 + f(s1,s2,i,j+1);
        return t[i][j] = min(rep,min(ins,del));
    }
    
    int minDistance(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return f(s1,s2,0,0);
    }
};