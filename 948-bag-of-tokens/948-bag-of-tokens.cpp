class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n==0)    return 0;
        sort(begin(tokens),end(tokens));
        if(power<tokens[0])  return 0;
        int start = 0;
        int end = tokens.size()-1;
        int points = 0,ans=0;
        while(start<=end){
            if(power>=tokens[start]){
                power = power - tokens[start];
                start++;
                ans = max(ans,++points);
            }else if(points){
                power = power + tokens[end];
                end--;
                points--;
            }else{
                break;
            }
        }
        return ans;
    }
};