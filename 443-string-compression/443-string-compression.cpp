class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int n = chars.size();
        for(int i=0;i<n;){
            char ch = chars[i];
            ans.push_back(ch);
            int cnt = 1;
            int j = i+1;
           while(j<n && chars[j] == ch){
                cnt++;
               j++;
            }
            if(cnt>1){
                string temp = to_string(cnt);
                for(int x=0;x<temp.size();x++)  ans.push_back(temp[x]);
            }
            
            i = j;
        }
        chars = ans;
        return ans.size();
    }
};