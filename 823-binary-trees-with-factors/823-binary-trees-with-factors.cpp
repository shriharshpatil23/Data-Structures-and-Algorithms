class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0;
        unordered_map<ll,ll> mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            ll curr_ans = 1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j])   continue;
                
                ll num1 = arr[j];
                ll num2 = arr[i]/arr[j];
                
                curr_ans = (curr_ans + (mp[num1]*mp[num2])%MOD)%MOD;
            }
            ans = (ans+curr_ans)%MOD;
            mp[arr[i]]=curr_ans;
        }
        return (int)ans;
    }
};