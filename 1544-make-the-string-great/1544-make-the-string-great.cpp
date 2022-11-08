class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(isupper(s[i]) && !isupper(st.top()) && s[i]==toupper(st.top())){
                    st.pop();
                }else   if(islower(s[i]) && !islower(st.top()) && s[i]==tolower(st.top())){
                    st.pop();                    
                }else{
                st.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};