class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')  return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }else   if(isVowel(s[start]) && !isVowel(s[end])){
                end--;
            }else   if(!isVowel(s[start]) && isVowel(s[end])){
                start++;
            }else{
                start++;
                end--;
            }
        }
        return s;
    }
};