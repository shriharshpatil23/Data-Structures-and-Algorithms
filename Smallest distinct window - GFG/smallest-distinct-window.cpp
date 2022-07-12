// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    bool isValid(string s, set<char> &st){
        set<char> st2 (s.begin(),s.end());
        
        return st == st2;
    }
    
    int findSubString(string str)
    {int i=0, n=str.length(), org=0;
        vector<int> ct(256), count(256);
        for(int x=0; x<n; x++){
            if(ct[str[x]]==0)
                org++;//count diff character in original array
            ct[str[x]]++;
        }
        int ans=n, len=0, j=0, d=0;
        for(int i=0; i<n; i++){
            len++;
            if(count[str[i]]==0)
                d++; //distinct char in window
            count[str[i]]++;
            while(j<=i && d==org){ //while d==org and
            // starting pointer j<=i
                ans=min(ans, len);
                if(count[str[j]]==1)
                    d--;
                count[str[j++]]--;
                len--;
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends