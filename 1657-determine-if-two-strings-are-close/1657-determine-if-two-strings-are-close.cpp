class Solution {
public:
    bool closeStrings(string word1, string word2) {
//         if(word1.length()!=word2.length())  return false;
//         map<char,int> mp1,mp2;
//         for(auto x : word1) mp1[x]++;
//         for(auto x : word2){
//           if(mp1.find(x)==mp1.end())  return false;  
//           mp2[x]++;  
//         } 
        
//         map<int,int> m1,m2;
//         for(auto x : mp1){
//             m1[x.second]++;
//         }
//         for(auto x : mp2){
//             m2[x.second]++;
//         }
//         return m1==m2;
        
        vector<int>w1(26,0),w2(26,0),w3(26,0),w4(26,0);
        for(char c:word1)
            w1[c-'a']++,w3[c-'a'] = 1;
    
        for(char c:word2)
            w2[c-'a']++,w4[c-'a'] = 1;
        
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&w3==w4;
        
    }
};