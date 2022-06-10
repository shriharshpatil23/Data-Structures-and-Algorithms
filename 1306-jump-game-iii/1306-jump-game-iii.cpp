class Solution {
public:
    int t[50001];
    int vis[50001];
    int n ;
    bool helper(int i, vector<int>& arr){
        if(i<0 || i>=n || vis[i]==1)    return false;
        
        if(t[i]!= -1)   return t[i];
        
        vis[i]=1;
        
        if(arr[i]==0)   return true;
              
        return t[i]=helper(i-arr[i],arr)||helper(i+arr[i],arr)  ;
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        memset(t,-1,sizeof(t));
        memset(vis,0,sizeof(vis));
        return helper(start,arr);
    }
};