class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mp;
        for(auto x : changed)   mp[x]++;
        sort(begin(changed),end(changed));
        vector<int> ans;
        for(auto x : changed){
            if(mp.count(x)>0 ){
                mp[x]--;
                if(mp[x]==0)    mp.erase(x);
                int val = x*2;
                if(mp.find(val)!=mp.end()){
                    mp[val]--;
                    if(mp[val]==0)    mp.erase(val);
                    ans.push_back(x);
                }
            }
        }
        if(ans.size()!=changed.size()/2 || changed.size()%2!=0)    return {};
        return ans;
    }
};