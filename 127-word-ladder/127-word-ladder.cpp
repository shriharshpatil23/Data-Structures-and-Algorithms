class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        //Base Condition        
        bool ava = false;
        for(auto x : wordList){
            if(x==endWord){
                ava = true;
                break;
            }
        }
        if(ava==false)  return 0;
        //Creating map for storing elements after 1 change
        
        
        
        
        // unordered_map<string,set<string>> mp;
        // for(auto x : wordList){
        //     int n = x.size();
        //     for(int i=0;i<n;i++){
        //         string tmp = x;
        //         tmp[i]='?';
        //         mp[tmp].insert(x);
        //     }
        // }
        
        
        
        //vis vector so that we cant get in loop
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> q;    //for bfs
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string fw = q.front();
                q.pop();
                dict.erase(fw);
                if(fw == endWord)   return ans;
                for(int i=0;i<fw.size();i++){
                   char c = fw[i];
                    for (int k = 0; k < 26; k++) {
                        fw[i] = 'a' + k;
                        if (dict.find(fw) != dict.end()) {
                            q.push(fw);
                        }
                     }
                    fw[i] = c;                    
                }
            }
            ans++;
        }
        return 0;
    }
};