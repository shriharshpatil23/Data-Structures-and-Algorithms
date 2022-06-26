class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
//         int start = 0;
//         int n = card.size();
//         int end = n - k;
//         int totalSum = 0;
        
//         for(int i=end-1;i<n;i++){
//             totalSum += card[i];
//         }
//         int ans = totalSum;
//         while(end<n){
//             totalSum = totalSum - card[++start] + card[++end];
//             ans = max(ans,totalSum);
//         }
//         return ans;
        
         int res=0, n=cardPoints.size(), s=0;
        for(int i=n-k; i<n;i++) res+=cardPoints[i]; // take k right
        for(int i=0, s=res;i<k;i++) {
            s-=cardPoints[n-k+i];
            s+=cardPoints[i];
            res=max(res,s);
        }
        return res;
    }
};