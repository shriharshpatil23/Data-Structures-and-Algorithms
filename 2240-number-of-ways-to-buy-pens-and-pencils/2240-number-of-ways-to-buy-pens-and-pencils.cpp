class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        long long pen = 0;
        while(pen <= total) {
            long long left = total - pen;
            long long pencil = left/cost2 + 1;
            ways += pencil;
            pen += cost1;
        }
        return ways;
    }
};