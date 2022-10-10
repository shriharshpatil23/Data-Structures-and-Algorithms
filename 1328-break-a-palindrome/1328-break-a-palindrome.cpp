class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            if(s[start]!=s[end])    return false;
            
            start++;
            end--;
        }
        return true;
    }
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<=1)    return "";
        vector<string> vec;
        for(char i = 'a';i<='z';i++){
            for(int j=0;j<palindrome.size();j++){
                string tmp = palindrome;
                if(tmp[j]!=i){
                    tmp[j]=i;
                    if(isPalindrome(tmp)==false)   vec.push_back(tmp);
                }
            }
        }
        sort(vec.begin(),vec.end());
        return vec[0];
    }
};