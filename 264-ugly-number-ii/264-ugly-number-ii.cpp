class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(1691);
        ugly[0]=1;
        int p2 =0,p3=0,p5=0;
        for(int i=1;i<1691;i++){
            ugly[i]= min({ugly[p2]*2,ugly[p3]*3,ugly[p5]*5});
            if(ugly[i]==ugly[p2]*2)  p2++;
            
            if(ugly[i]==ugly[p3]*3)  p3++;
            
            if(ugly[i]==ugly[p5]*5)  p5++;
        }
        return ugly[n-1];
    }
};