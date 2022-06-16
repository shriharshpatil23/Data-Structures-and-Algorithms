class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          //using unorderd_map to store  and frequency of one vector 
        unordered_map<int,int>m;
        vector<int>ans;
        for(auto val:nums1)
        {
            m[val]++;
        }
        //if val from 2nd vector is present in map then
        //put it in output vector
        //also decrease the count
        for(auto val:nums2)
        {
            if(m[val]>0)
            {
                ans.push_back(val);
                m[val]--;
            }
        }
        return ans;
    }
};