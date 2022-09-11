class Solution {
public:
    /*
    1. First, we need to zip(efficiency, speed) of n engineers.
    2. We need to sort n engineers by the decreasing order of their efficiency.
    3. When we iterate over engineers by decreasing order of efficiency, we need to use     minHeap structure to keep k largest speed engineers so far (top of minHeap is min s     peed,we can remove the lowest speed engineer when size of minHeap greater than k in     O(1)).
    4. The idea to keep k largest emenents is the same with 215. Kth Largest Element in     an Array
    */
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({eff[i],speed[i]});
        }
        sort(rbegin(arr),rend(arr));
        long sum =0 ,ans = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x : arr){
            int ef = x.first;
            int spd = x.second;
            pq.push(spd);
            sum += spd;
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,ef*sum);
        }
        ans = ans%1000000007;
        return (int)ans;
    }
};