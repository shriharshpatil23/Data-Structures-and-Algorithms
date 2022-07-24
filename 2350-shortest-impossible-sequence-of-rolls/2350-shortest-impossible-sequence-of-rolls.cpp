class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1, satisfied = k;
        map<int,int> mp;
        for(int i = 0; i < rolls.size(); i++){
            if(mp.find(rolls[i]) == mp.end()){
                satisfied -= 1;
                mp[rolls[i]] += 1;
                if(satisfied == 0){
                    ans += 1;
                    satisfied = k;
                    mp.clear();
                }
            }
        }
        return ans;
    }
};