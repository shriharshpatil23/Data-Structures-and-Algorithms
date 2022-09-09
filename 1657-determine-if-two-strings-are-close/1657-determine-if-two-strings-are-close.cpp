class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())  return false;
        map<char,int> mp1,mp2;
        for(auto x : word1) mp1[x]++;
        for(auto x : word2){
          if(mp1.find(x)==mp1.end())  return false;  
          mp2[x]++;  
        } 
        
        map<int,int> m1,m2;
        for(auto x : mp1){
            m1[x.second]++;
        }
        for(auto x : mp2){
            m2[x.second]++;
        }
        return m1==m2;
    }
};