class Solution {
public:
//     string substring(int i, int k , string s){
//         string ans = "";
//         for(int j=0;j<k;j++){
//             ans.push_back(s[i+j]);
//         }
//         return ans;
//     }
    
// void solution(string record, int start, int last,set<string> &st)
// {
// 	if (start == last)
// 	{
// 		//printf(" %s \n", record);
//         st.insert(record);
// 		return;
// 	}
// 	record[start] = '0';
// 	solution(record, start + 1, last,st);
// 	// change to 1
// 	record[start] = '1';
// 	solution(record, start + 1, last,st);
// }
// void binaryString(int k,set<string> &st)
// {
// 	// N indicate digit in binary
// 	if (k <= 0)
// 	{
// 		return;
// 	}
// 	string record (k,'0');
// 	// printf(" Digit : %d \n", n);
// 	solution(record, 0, k,st);
// }
    
    bool hasAllCodes(string s, int k) {
      // set<string> st;
      //   binaryString(k,st);
      //   for(auto x : st){
      //       bool res = false;
      //       for(int i=0;i<=s.size()-k;i++){
      //           string tmp = substring(i,k,s);
      //           cout<<tmp<<endl;
      //           if(x == tmp){
      //               res = true;
      //           }
      //       }
      //       if(res == false)    return false;
      //   }
      //   return true;  
        
        
        //optimal
        
        
        int n = s.size();
        int pow2 = 1 << k;
        unordered_set<string> st;
        
        if(n<k) return false;
        
        // generate all string of k bits
        for(int i=0; i<=n-k; i++)
        {
            string t = s.substr(i,k);
            if(st.find(t) == st.end())
            {
                st.insert(t);
                pow2--;
            }
            if(pow2 == 0) return true;
        }
        
        return st.size() == false;
        
    }
};