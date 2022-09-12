class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)    return 1;
        int ans =1;
        int diff = 1;
        int direction = 0;
        while(n>1){
            if(n&1 || direction == 0 ){
                ans += diff;
            }
            diff=diff*2;
            direction = !direction;
            n=n/2;
        }
        return ans;
    }
};