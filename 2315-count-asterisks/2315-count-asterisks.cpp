class Solution {
public:
//     string helper(string s){
//         string  ans = "";      
//         int cnt = 0;
  
//         bool flg = false;
        
//         for(int i = 0; i < s.size(); i++) {
//             if(s[i] != '|' && !flg && cnt == 0) {
//                 ans += s[i];
//             }
//             else if(flg && cnt == 1 && s[i] == '|') {
//                 flg = false;
//                 cnt = 0;
//             }
//             else if(s[i] == '|'){
//                 flg = true;
//                 cnt++;
//             }
//         }
//         return ans;
//     }
    
    int countAsterisks(string s) {
        int n = s.length();
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                cnt++;
            }else   if(cnt%2==0 && s[i]=='*'){
                ans++;
            }
        }
        return ans;
    }
};