class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00;
        long long num = n;
        num = abs(num);
        while(num){
            if(num%2){
                ans  = ans * x;
                num--;
            }else{
                x = x*x;
                num = num/2;
            }
        }
        if(n<0) ans = 1/ans;
        
        return ans;
    }
};