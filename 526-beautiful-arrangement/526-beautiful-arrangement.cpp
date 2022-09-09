class Solution {
public:
    // bool isBeautiful(vector<int> arr,int n){
    //     bool cond1 = true;
    //     for(int i=0;i<n;i++){
    //         if(arr[i]%(i+1) !=0){
    //             cond1 = false;
    //             break;
    //         }
    //     }
    //     bool cond2 = true;
    //     for(int i=1;i<=n;i++){
    //         if(i%arr[i-1]!=0){
    //             cond2 = false;
    //             break;
    //         }
    //     }
    //     return cond1 || cond2;
    // }
    void helper(int idx, vector<int>&arr,int &ans){
        if(idx==arr.size()){
            ans++;
            return ;
        }
        for(int i=idx;i<arr.size();i++){
            if((idx+1)%arr[i] == 0 || arr[i]%(idx+1)==0){
                swap(arr[i],arr[idx]);
                helper(idx+1,arr,ans);
                swap(arr[i],arr[idx]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int ans = 0;
        helper(0,arr,ans);
        return ans;
    }
};