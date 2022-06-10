class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // vector<int> freq(26,0);
        // for(auto x : letters){
        //     freq[x-'a']++;
        // }
        // int i = target - 'a' +1;
        // int ans ;
        // while(i<26){
        //     if(freq[i]>0){
        //         ans = i;
        //         break;
        //     }
        //     i++;
        // }
        // char res = 97 + ans;
        // return res;
        
        // Binary search Solution
        
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};