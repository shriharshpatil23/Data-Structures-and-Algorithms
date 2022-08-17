class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto x : words){
            string tmp = "";
            for(int i=0;i<x.size();i++){
                tmp = tmp + morse[x[i]-'a'];
            }
            s.insert(tmp);
        }
        return s.size();
    }
};