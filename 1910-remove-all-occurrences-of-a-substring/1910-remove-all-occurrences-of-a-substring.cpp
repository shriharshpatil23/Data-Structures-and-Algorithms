class Solution {
public:
    bool isMatching(stack<char>st, string part){
        int n = part.size();
        int j = n-1;
        while(!st.empty() && j>=0){
            if(st.top()!=part[j])   return false;
            
            j--;
            st.pop();
        }
        if(j==-1)   return true;
        return false;
    }
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int p = part.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=p && isMatching(st,part)){
                int t = p;
                while(t--){
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};