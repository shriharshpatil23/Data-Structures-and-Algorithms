// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sumA =0 ;
        int sumB = 0;
        set<int> a,b;
        for(int i=0;i<n;i++){
            sumA += A[i];
            a.insert(A[i]);
        }    
        
        for(int i=0;i<m;i++){
             sumB += B[i];
             b.insert(B[i]);
        }   
       int diff = abs(sumA - sumB);
       if(diff &1)    return -1;
       if(sumA > sumB){
           for(auto x : a){
               if(b.find(x- (diff)/2)!= b.end()){
                   return true;
               }
           }
       }else{
           for(auto x : b){
               if(a.find(x- (diff)/2)!= a.end()){
                   return true;
               }
           }
       }
       return -1;
	}
};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends