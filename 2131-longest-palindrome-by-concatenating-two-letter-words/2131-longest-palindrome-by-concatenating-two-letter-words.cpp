class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto x : words) mp[x]++;
        int ans = 0;
        int odd_count = 0;
        for(auto x : words){
            string rev = x;
            reverse(begin(rev),end(rev));
            if(x!=rev && mp[x]>0 && mp[rev]>0){
                mp[x]--;
                mp[rev]--;
                ans+=4;
            }
            else    if(x==rev && mp[x]>1){
                ans+=4;
                mp[x]-=2;
            }else   if(x==rev && odd_count==0 && mp[x]>0){
                odd_count++;
                ans+=2;
                mp[x]--;
            }
        }
        return ans;
    }
};