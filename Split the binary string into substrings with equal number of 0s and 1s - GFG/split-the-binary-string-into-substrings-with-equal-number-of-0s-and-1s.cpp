// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int cnt_0 = 0,ans=0;
        int cnt_1 = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')   cnt_0++;
            
            if(str[i]=='1')   cnt_1++;
            
            if(cnt_0 ==cnt_1)   ans++;
        }
        if(cnt_0 != cnt_1)  return -1;
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends