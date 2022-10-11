class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long a=LONG_MAX;
        long b=LONG_MAX;
        long c=LONG_MAX;
        for(auto x : nums){
            if(x<=a){
                a=x;
            }else   if(x<=b){
                b=x;
            }else   if(x<=c){
                c=x;
            }
        }
        if(c==LONG_MAX)  return false;
        return true;
    }
};