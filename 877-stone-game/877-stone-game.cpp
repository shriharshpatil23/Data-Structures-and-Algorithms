class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        deque<int> dq;
        for(auto x : piles) dq.push_back(x);
        bool alice = true;
        int a = 0;
        int b = 0;
        while(!dq.empty()){
            int fr = dq.front();
            int bk = dq.back();
            if(fr>bk){
                dq.pop_front();
                if(alice)   a+= fr,alice=false;
                else    b+= fr,alice=true;
            }else{
                dq.pop_back();
                if(alice)   a+=bk,alice=false;
                else    b+= bk, alice=true;
            }
        }
//         if(a>b) return true;
        
//         return false;
        return true;
    }
};