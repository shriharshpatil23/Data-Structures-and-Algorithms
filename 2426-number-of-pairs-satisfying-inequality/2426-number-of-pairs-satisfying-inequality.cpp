#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(x) : returns iterator to the xth element in pbds
// order_of_key(x) : gives number of elements strictly less than x
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> x(n);
        for(int i=0;i<n;i++){
            x[i]=nums1[i]-nums2[i];
        }        
        pbds os;
        long long ans=0;
     
        for(int i=0;i<n;i++){
            int cur=x[i]+diff;
            cur++;
            ans+=(long long)os.order_of_key(cur);
            os.insert(x[i]);
            
        }
        return ans;
    }
};