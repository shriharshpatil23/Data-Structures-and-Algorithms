#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
long long MOD = 1000000007;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(x) : returns iterator to the xth element in pbds
// order_of_key(x) : gives number of elements strictly less than x
class Solution {
public:
    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        map<int,int>mp;
        int ans =0;
        for(int i=0;i<n;i++){
            arr[i]=nums[i]-rev(nums[i]);
            mp[arr[i]]++;
        }
        for(auto x : mp){
            ans += (((x.second-1)%MOD)*((x.second)%MOD)/2)%MOD;
        }
        return ans%MOD;
    }
};