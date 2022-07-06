class Solution {
public:
    string reverseWords(string s) {
         stringstream ss(s);
        vector<string> vec;
        string tmp;
        while(getline(ss,tmp,' ')){
            vec.push_back(tmp);
        }
        string ans = "";
        int n = vec.size();
        for(int i=n-1;i>-1;i--){
            if(vec[i].size()!=0){
                ans = ans  + vec[i] + " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};