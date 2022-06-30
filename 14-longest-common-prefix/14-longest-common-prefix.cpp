class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans ="";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int len = strs[0].size();
        string start = strs[0];
        string end = strs[n-1];
        for(int i=0;i<len;i++){
            if(start[i]==end[i]){
                ans.push_back(start[i]);
            }else{
                break;
            }
        }
        return ans;
    }
};