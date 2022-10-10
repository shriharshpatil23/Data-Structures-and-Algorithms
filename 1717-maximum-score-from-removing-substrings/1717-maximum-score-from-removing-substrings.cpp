class Solution {
public:
    int cnt_pairs(string &s, char a, char b){
        int n = s.size();
        int ans = 0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(!st.empty() && (s[i]==b &&st.top()==a)){
                ans++;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string tmp = "";
        while(!st.empty()){
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(begin(tmp),end(tmp));
        s = tmp;
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        int ca = 0;
        int cb = 0;
        if(x>y){
            ca = cnt_pairs(s,'a','b');
            cb = cnt_pairs(s,'b','a');
        }else{
            cb = cnt_pairs(s,'b','a');
            ca = cnt_pairs(s,'a','b');
        }
        return ca*x + cb*y;
    }
};