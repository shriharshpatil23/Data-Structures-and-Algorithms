class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        for(int i=0;i<capacity.size();i++){
            capacity[i] -= rocks[i]; 
        }
        sort(capacity.begin(),capacity.end());
        int cnt = 0;
        for(int i=0;i<capacity.size() && a > 0;i++){
            if(a < capacity[i]) break;
            
            a = a - capacity[i];
            cnt++;
        }
        return cnt;
    }
};

// 1 1 0 1
// 0 1 1 1
// 0 0 0 1