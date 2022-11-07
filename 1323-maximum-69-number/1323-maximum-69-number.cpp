class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        string tmp = to_string(num);
        int n = tmp.size();
        for(int i=0;i<n;i++){
            if(tmp[i]=='6'){
                tmp[i]='9';
                break;
            }
        }
        ans = max(ans,stoi(tmp));
        return ans;
    }
};