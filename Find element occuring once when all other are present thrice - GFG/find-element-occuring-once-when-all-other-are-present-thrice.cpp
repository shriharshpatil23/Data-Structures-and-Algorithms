// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool setBit(int n , int pos){
      return (n | (1<<pos));
  }
  bool getBit(int n , int pos){
      return (n & (1<<pos))!=0;
  }
    int singleElement(int arr[] ,int N) {
        int ans=0;
     for(int i=0;i<=31;i++){
         int count=0;
        for(int j=0;j<N;j++) {
            if((arr[j]&(1<<i))==0)
                continue;
            else 
                count++;
        }
        if(count%3==1)
              ans+=1<<i;
     }
     return ans;
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
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends