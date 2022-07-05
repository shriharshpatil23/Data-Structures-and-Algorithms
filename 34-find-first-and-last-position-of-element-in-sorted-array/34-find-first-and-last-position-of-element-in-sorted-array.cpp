class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int start = 0;
        int end = a.size()-1;
        int mid ;
        vector<int> ans(2,-1);
        //for 1 st occurence
        while(start<=end){
            mid = start + (end - start)/2;
            if(a[mid]==target){
                ans[0]=mid;
                end = mid - 1;
            }else   if(a[mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        //for last occurence
        start = 0;
        end = a.size()-1;
        while(start<=end){
            mid = start + (end - start)/2;
            if(a[mid]==target){
                ans[1]=mid;
                start = mid + 1;
            }else   if(a[mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};