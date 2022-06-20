class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        stack<int> index;
        for(int i=0; i<s.size();i++){
            if(st.empty() || st.top().first!= s[i]){
                st.push({s[i],1});
                index.push(i);
            }else{
                st.top().second++;
            }
            
            if(st.top().second == k){
                s.erase(index.top(),k);
                st.pop();
                i = index.top()-1;
                index.pop();
            }
        }
        return s;
    }
};