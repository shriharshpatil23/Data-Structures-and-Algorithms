class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //map<int,int> mp;
//         for(auto x : piles) mp[x]++;       
//         priority_queue<int> pq;
//         priority_queue<int,vector<int>, greater<int>> pq_min;
//         int ans = 0;
//         int m = n/3;
//         for(int i=0;i<m;i++){
//             //for alice
//             int tp = pq.top();
//             if(mp.find())
//         }
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int bob = 0;
        int alice = n-1;
        int me = n-2;
        int ans = 0;
        while(bob<me){
            cout<<piles[me]<<" "<<me<<endl;
            ans += piles[me];
            me = me - 2;
            alice -= 2;
            bob++;
        }
        return ans;
    }
};