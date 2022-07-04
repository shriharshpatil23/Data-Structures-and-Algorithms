class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>>>pq;
        for(auto x:nums){
            pq.push({x.size(),x});
            if(pq.size()>k) pq.pop();
        }
        return pq.top().second;
    }
};