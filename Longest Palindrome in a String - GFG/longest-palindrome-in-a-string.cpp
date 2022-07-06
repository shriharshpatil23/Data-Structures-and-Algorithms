// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
  bool isPalindrome(string str, int s, int e){
     while(s < e){
         if(str[s] != str[e]){
             return false;
         }
         s++;
         e--;
     }
     return true;
 }
    string longestPalin (string S) {
        int n = S.length();
       int maxLen = 0;
       string ans = "";
       
       if(n == 1){
           return S;
       }
       for(int i = 0; i<n-1; i++){
           for(int j = i; j<n; j++){
               
               if(isPalindrome(S, i, j) && maxLen < (j-i+1)){
                   
                   maxLen = j-i+1;
                   ans = S.substr(i, j-i+1);
               }
           }
       }
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends