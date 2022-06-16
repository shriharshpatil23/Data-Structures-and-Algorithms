class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          //using unorderd_map to store  and frequency of one vector 
        // unordered_map<int,int>m;
        // vector<int>ans;
        // for(auto val:nums1)
        // {
        //     m[val]++;
        // }
        // //if val from 2nd vector is present in map then
        // //put it in output vector
        // //also decrease the count
        // for(auto val:nums2)
        // {
        //     if(m[val]>0)
        //     {
        //         ans.push_back(val);
        //         m[val]--;
        //     }
        // }
        // return ans;
         sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;
				j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
        }
        return res;
    }
};