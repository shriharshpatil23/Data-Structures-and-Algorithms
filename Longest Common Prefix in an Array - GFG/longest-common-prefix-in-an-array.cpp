// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
     if(N==1)
      return arr[0];
       int min_l= INT_MAX,index;
       for(int i=0;i<N;i++)
       {
           if(arr[i].length()<=min_l)
           {
               min_l=arr[i].length();
               index=i;
           }
       }
       for(int i=0;i<N;i++)
       {
           if(i!=index)
           {
               while((arr[i].substr(0,min_l)!=arr[index].substr(0,min_l))&&min_l>0)
               {
                   min_l--;
               }
               if(min_l==0)
               {
                   return "-1";
               }
           }
           
       }
       return arr[index].substr(0,min_l);
   }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends