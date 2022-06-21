// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
   int his(int *arr,int n){
     vector<int> nsel(n);
     vector<int> nser(n);
     stack<int> st;
     for(int i=0;i<n;i++){
         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
         if(st.size()==0) nsel[i]=-1;
         else nsel[i]=st.top();
         st.push(i);
     }
     while(!st.empty()) st.pop();
     for(int i=n-1;i>=0;i--){
         while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
         if(st.size()==0) nser[i]=n;
         else nser[i]=st.top();
         st.push(i);
     }
     int omax=0;
     for(int i=0;i<n;i++){
         int area=(nser[i]-nsel[i]-1)*arr[i];
         omax=max(omax,area);
     }
     return omax;
 }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = his(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!= 0){
                    M[i][j]+= M[i-1][j];
                }else{
                    M[i][j]= 0;
                }
            }
            area = max(area, his(M[i],m));
        }
        return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends