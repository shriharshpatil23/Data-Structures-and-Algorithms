class Solution {
public:
    int titleToNumber(string columnTitle) {
       //  int n = columnTitle.size();
       // // if(n==1)    return columnTitle[0]-'A' + 1;
       // int count=0, sum=0;
       //  for(int i=columnTitle.length()-1; i>=0; i--) {
       //      sum+=pow(26, count++)*(columnTitle[i]-'A'+1);
       //  }
       //  return sum; 
        int ans = 0;
        for(auto x : columnTitle){
            int rem = x - 'A' + 1;
            ans = ans*26 + rem;
        }
        return ans;
    }
};