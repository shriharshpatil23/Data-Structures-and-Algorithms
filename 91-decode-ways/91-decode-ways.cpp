class Solution {
public:
    int t[101];
    int helper(int i , string s){
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(i>=s.size()-1)return 1;
        string b = s.substr(i,2);
        
        if(t[i]!= -1)   return t[i];
        
        int way1 = helper(i+1,s);
        int way2=0;
        if(stoi(b)<=26&&stoi(b)>0){
            way2 = helper(i+2,s);
        }
        return t[i] = way1+way2;
    }
    
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
       return helper(0,s);        
    }
};