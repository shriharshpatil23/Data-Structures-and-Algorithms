class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto x : arr)   mp[x]++;
        
        set<int> uni;
        for(auto x : mp){
            if(uni.find(x.second)!=uni.end())   return false;
            
            uni.insert(x.second);
        }
        return true;
    }
};