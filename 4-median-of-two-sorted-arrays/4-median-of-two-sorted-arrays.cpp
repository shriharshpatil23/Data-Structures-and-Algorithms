class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        vector<int> median;
        for(auto x : nums1) median.push_back(x);
        
        for(auto x : nums2) median.push_back(x);
        
        sort(median.begin(),median.end());
        
        double ans ;
        if(n %2 ==0){
            return double((median[n/2] + median[(n/2) -1])/2.00000) ;
          
        }else{
            ans = median[n/2];
        }
        return ans;
    }
};