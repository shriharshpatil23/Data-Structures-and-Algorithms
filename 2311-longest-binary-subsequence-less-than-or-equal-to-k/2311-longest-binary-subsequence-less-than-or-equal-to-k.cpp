class Solution {
public:
    // int ans ;
    // void helper(int i , string s, int k , string tmp){
    //     if(i<=0) return ;
    //     int val ;
    //     if(tmp.size()==0)   val = INT_MAX;
    //     else    val = stoi(tmp,0,2);
    //     int n = tmp.size();
    //     if(val <= k)    ans = max(ans,n);
    //     tmp.push_back(s[i]);
    //     helper(i-1,s,k,tmp);
    //     tmp.pop_back();
    // }
    
    int longestSubsequence(string s, int k) { // unsigned long long value = std::stoull(s, 0, 2); 
        // ans = 0;
        // helper(s.size()-1,s,k,"");
        // return ans;
        
          int n=s.size();
        int ans=0;
        int cnt=0;
        int j=n-1;
        for(int i=0;i<31&&j>=0;i++,j--){
            int num=ans;
            if(s[j]=='1') num|=(1<<i);
            if(num>k) break;
            cnt++;
            ans=num;
        }
        while(j>=0){
            if(s[j]=='0') cnt++; 
            j--;
        }
        return cnt;
    }
};