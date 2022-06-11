// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)    return 1;
        
        int start = 1;
        int end = n;
        int mid ;
        while(start <end){
            mid = start + (end - start)/2;
            
            if(!isBadVersion(mid)) start= mid+1;
            else    end = mid;
            
        }
        return start;
    }
};