class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int n = arr[i];
            for(int j=i+1;j<arr.size();j++){
                if( n == 2*arr[j] || (n==arr[j]/2 && arr[j]%2 ==0) ){
                    return true;
                }
            }
        }
                   return false;
    }
};