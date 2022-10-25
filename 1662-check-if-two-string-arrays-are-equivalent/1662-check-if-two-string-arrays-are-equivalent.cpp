class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 ="";
        for(auto x : word1){
            str1.append(x);
        }
        string str2 ="";
        for(auto x : word2){
            str2.append(x);
        }
        
        if(str1==str2)  return true;
        
        
        return false;
        
    }
};