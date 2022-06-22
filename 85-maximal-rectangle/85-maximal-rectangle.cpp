class Solution {
public:
    vector<int> nextSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])    st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            else    ans[i]=-1;
            
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])  st.pop();
            
            if(!st.empty()) ans[i]=st.top();
            else    ans[i]=-1;
            
            st.push(i);
        }
        return ans;
    }
    int histogram(vector<int> arr){
        int area = 0;
        vector<int> ns = nextSmaller(arr,arr.size());
        vector<int> ps = prevSmaller(arr,arr.size());
        
        for(int i=0;i<arr.size();i++){
            if(ns[i]== -1) ns[i] = arr.size();
            int newArea = arr[i]*(ns[i] - ps[i] -1);
            area = max(area,newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(n + m == 2) return matrix[0][0] == '1';
        vector<vector<int>> mat(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')   mat[i][j]=1;
            }
        }
        int ans = 0;
        vector<int> tmp = mat[0];
        ans = max(ans,histogram(tmp));
        for(int i=1;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]==0)    tmp[j]=0;
                else    tmp[j] += 1;
            }
            ans = max(ans,histogram(tmp));
        }
        return ans;
    }
};