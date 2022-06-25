// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    set<string> st;
    int helper(int i, string s){
        if(i>=s.size()) return 1;
        
        string tmp ="";
        for(int j=i;j<s.size();j++){
            tmp += s[j];
            if(st.find(tmp)!=st.end()){
                if(helper(j+1,s))   return 1;
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
       for(auto x : B)  st.insert(x);
       return helper(0,A);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends