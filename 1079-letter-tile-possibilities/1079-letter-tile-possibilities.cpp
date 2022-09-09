class Solution {
public:
    int fact[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
    void helper(vector<int>&freq,int &ans){
        for(int i=0;i<26;i++){
            if(freq[i]){
                freq[i]--;
                ans++;
                helper(freq,ans);
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        int n = tiles.size();
        for(int i=0;i<n;i++) freq[tiles[i]-'A']++;
        int ans = 0;
        // for(int i=0;i<26;i++){
        //     ans = ans/fact[freq[i]];
        // }
        helper(freq,ans);
        return ans;
    }
};