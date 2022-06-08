class Solution {
public:
    int removePalindromeSub(string s) {
       if(s.size() == 0)
           return 0;
        string res = s;
        reverse(res.begin(),res.end());
        if(s == res) 
            return 1;
         else
             return 2;
        
    }
};