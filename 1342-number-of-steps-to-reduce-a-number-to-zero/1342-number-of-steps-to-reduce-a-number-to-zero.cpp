class Solution {
public:
    int numberOfSteps(int n) {
        int steps = 0;
        while(n){
            if(n%2==0){
                n = n/2;
                steps++;
            }else{
                n = n - 1;
                steps++;
            }
        }
        return steps;
    }
};