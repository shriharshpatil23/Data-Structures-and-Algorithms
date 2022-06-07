class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
       stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')   st.push(s[i]);
            else{
                if(st.empty())   cnt++;
                else    st.pop();
            }
        }
        cnt += st.size();
        return cnt;
    }
};