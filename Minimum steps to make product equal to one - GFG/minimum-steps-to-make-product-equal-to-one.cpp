// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
           
       int zeros=0, product=1 , steps=0;
       
       for(int i=0; i<N ; i++)
        {
            
            if(arr[i]>=1)
             {
             steps=steps+arr[i]-1 ;
             
             }
            else if(arr[i]<=-1)
             {
                 steps=steps-arr[i]-1;
                 product=product*(-1);
                 
             }
             else
              zeros++;
        }
        
        if(product>0 ) return steps+zeros;
        else if (product<0 && !zeros) return steps+2;
        else
         return steps+zeros;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends