class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> umap;
        vector<int> freq;
        for(char c:s){
            umap[c]++;
        }
        for(auto it:umap){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        //vector<int> freqU;
        unordered_map<int,int> freqU;
        for(int i=0;i<freq.size();i++){
            if(i!=0)
            while(freqU.find(freq[i])!=freqU.end() && freq[i]>0){
                freq[i]--;
            }
            freqU[freq[i]]=1;
        }
        int c=0;
        for(int i=0;i<freq.size();i++){
            c+=freq[i];
        }
        return s.size()-c;
        
    }
};