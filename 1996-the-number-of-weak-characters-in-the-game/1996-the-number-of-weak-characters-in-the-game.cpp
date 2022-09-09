class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size();
        sort(prop.begin(),prop.end(),cmp);
        int ans = 0;
        int mx = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(prop[i][1]<mx)   ans++;
            
            mx=max(mx,prop[i][1]);
        }
        return ans;
    }
};