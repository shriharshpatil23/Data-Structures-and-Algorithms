class Solution {
public:
    
//     string sub(string s , int i , int j){
//         string ans = "";
//         for(int c =i ; c<= j && c<s.size(); c++){
//             ans += s[c];
//         }
//         return ans;
//     }
    
//     bool isValid(string s){
//         stack <char> st;
        
//         int len = s.length();
//         for (int i = 0; i<len ; i++)//iterate over each and every elements
//         {
//              //if current element of the string will be opening bracket
//              //then we will just simply push it into the stack
//             if(s[i] == '(' || s[i] == '{' || s[i] == '[')
//                 st.push(s[i]);
//             else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
//             {
//                 if(st.empty())
//                     return false;
//                 else if(s[i] == ')' && st.top() != '(')
//                     return false;
//                 else if(s[i] == '}' && st.top() != '{')
//                     return false;
//                 else if(s[i] == ']' && st.top() != '[')
//                     return false;
//                 //if control reaches to that line,
//                 //it means we have got the right pair of brackets,
//                 //so just pop it.
//                 else 
//                     st.pop();
//             }
//         }
//         if(st.empty())
//             return true;
//         else
//             return false;
//     }
    
    int longestValidParentheses(string s) {
      stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans,i - st.top());
                }
            }
        }
        return ans;
    }
};