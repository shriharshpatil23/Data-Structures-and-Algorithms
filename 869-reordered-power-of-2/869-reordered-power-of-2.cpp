class Solution {
public:
    bool isPower2(string s){
        long long num = stoll(s);
        
        if(num==0)  return false;
        
        if(num==1)  return true;
        
        while(num>1){
            if(num%2!=0)    return false;
            
            num = num/2;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(begin(str),end(str));
        do {
            if(isPower2(str)==true && str[0]!='0')   return true;
        } while (next_permutation(str.begin(), str.end()));
        return false;
    }
};