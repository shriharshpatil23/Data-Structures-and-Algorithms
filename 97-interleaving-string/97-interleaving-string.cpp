class Solution {
public:
    int t[101][101];
     bool ans(string s1,string s2,string s3,int i,int j,int k){
        if(i==s1.length()){
            string s = s2.substr(j);
            string ss = s3.substr(k);
            return s==ss;
        }
        
        if(j==s2.length()){
            string s = s1.substr(i);
            string ss = s3.substr(k);
            return s==ss;
        }
        bool  ANS=false;
        if(t[i][j]!=-1) return t[i][j] == 1?true:false;
        
        bool left = false;
        if(s3[k]==s1[i]){
            
            left  =  ans(s1,s2,s3,i+1,j,k+1);
        }
        bool right = false;
        if(s3[k]==s2[j]){
            right = ans(s1,s2,s3,i,j+1,k+1);
        }
        ANS = left||right;
        return t[i][j] = ANS?1:0 ;
    }
    bool isInterleave(string s1, string s2, string s3) {
   //     vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
        memset(t,-1,sizeof(t));
        return ans(s1,s2,s3,0,0,0);        
    }
};