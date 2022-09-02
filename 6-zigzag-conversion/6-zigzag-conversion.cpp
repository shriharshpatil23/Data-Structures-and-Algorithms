class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)   return s;
        vector<string> vec(numRows+1);
        int n = s.size();
        int i = 0;
        int idx = 0;
        bool up_to_down = true;
        while(i<n){
            vec[idx].push_back(s[i++]);
            if(idx==numRows-1 && up_to_down){
                up_to_down = false;
            }
            if(idx==0 && up_to_down==false){
                up_to_down = true;
            }
            if(up_to_down)  idx++;
            else    idx--;
        }
        string ans;
        for(auto x : vec )  ans = ans + x;
        return ans;
    }
};