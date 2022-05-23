class Solution {
public:
    int t[601][101][101];
    
    int zero(string s){
        int ans = 0;
        for(auto x : s){
            if(x=='0')  ans++;
        }
        return ans;
    }
    
    int helper(int i ,vector<string>& strs, int m, int n ){
        if(i==strs.size())  return 0;  
                                            //Base Case
        if(m==0 && n == 0)  return 0;
        
        if(t[i][m][n] != -1)    return t[i][m][n];
        
        int n_zero = zero(strs[i]);
        int n_one = strs[i].size() - n_zero;
        
        //if we took it
        int take = 0;
        if(n_zero <= m && n_one <= n){
            take = 1 + helper(i+1,strs,m-n_zero,n-n_one);
        }
        //if we dont take it
        int not_take = helper(i+1,strs,m,n);
        
        return t[i][m][n] = max(take,not_take);        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t,-1,sizeof(t));
        return helper(0,strs,m,n);
    }
}; 