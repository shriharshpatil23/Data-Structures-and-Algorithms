class Solution {
public:
    int t[51][51];
    int helper(int i , int n ,vector<string> vowels ){
        if(i==vowels.size() && n !=0)    return 0;
        
        if(n==0){
           return 1;
        }
        
        if(t[i][n]!= -1)    return t[i][n];
        //if we took the element
        int ans = helper(i,n-1,vowels);
        //if we didnot took
        ans += helper(i+1,n,vowels);
        
        return t[i][n] = ans;
    }
    
    int countVowelStrings(int n) {
        vector<string> vowels ={"a","e","i","o","u"};
        memset(t,-1,sizeof(t));
        int ans = 0;
        return helper(0,n,vowels);
        //return ans;
    }
};