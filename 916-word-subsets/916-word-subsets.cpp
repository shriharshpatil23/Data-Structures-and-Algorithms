class Solution {
public:
 //   we know that order doesn't matter and all word of B are subset of word in A then only that word is considered. Having this in mind lets make a common word through B and just check that word as a subset in A.
//we can make a frequency map. instead of using Hashmap we can use array of 26(as all are lowercase) to store frequency.
    bool isSubsequence(string a, string b){
        map<char,int> mp;
        for(auto x : a) mp[x]++;
        
        for(auto x : b){
            if(mp.find(x)==mp.end())    return false;
            else{
                mp[x]--;
                if(mp[x]==0)    mp.erase(x);
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        // vector<string> ans;
        // for(auto x : words1){
        //     bool flg = true;
        //     for(auto y : words2){
        //         flg = flg && isSubsequence(x,y);
        //     }
        //     if(flg) ans.push_back(x);
        // }
        // return ans;
        vector<int>freq(26,0);           //create the frequency count of elements of B.
        for(auto x:B){
            vector<int>temp(26,0);
            for(auto y:x){
                temp[y-'a']++;
                freq[y-'a'] = max(freq[y-'a'],temp[y-'a']); 
            }
        }
        vector<string>res;
        for(auto x:A){
            vector<int>temp(26,0);
            for(auto y:x) temp[y-'a']++; //create freq count for all the elements in A
            bool flag=true;
            for(int i=0 ; i<26 ; i++)
                if(freq[i]>temp[i]) {flag=false;break;}         //check if fre count of B is subset of all A elements
            if(flag) res.push_back(x);
        }
        return res;
    }
};