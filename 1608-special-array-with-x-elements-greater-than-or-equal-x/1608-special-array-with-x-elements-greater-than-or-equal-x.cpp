class Solution {
public:
    int isSpecial(int x, vector<int> &nums){
        int cnt = 0;
        for(auto a : nums){
            if(a >= x)  cnt++;
        }
        return cnt;
    }
    
    int specialArray(vector<int>& nums) {
        int start = 0;
        int end = 1000;
        int mid ;
        while(start <= end){
            mid = start + (end - start)/2;
            if(isSpecial(mid,nums)==mid) return mid;
            else    if(isSpecial(mid,nums)<mid)    end = mid -1;
            else    start = mid + 1;
        }
        return -1;
    }
};