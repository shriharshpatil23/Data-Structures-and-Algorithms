class Solution {
public:
    void helper(int num , int n, int k , vector<int>&ans){
        if(n==0){
            ans.push_back(num);
        }else{
            int dig = num%10;
            if(dig + k <=9){
                helper(num*10 + dig + k , n-1,k,ans);
            }
            if(k!=0 && dig>=k ){
                helper(num* 10 + dig - k, n-1,k,ans);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            helper(i,n-1,k,ans);
        }
        return ans;
    }
};