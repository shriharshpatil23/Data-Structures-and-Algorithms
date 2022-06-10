class Solution
{
    public:
        int lengthOfLongestSubstring(string s) {
       	//     int n = s.size();
       	//     int ans = 0;
       	//     for(int i=0;i < n;i++){
       	//         unordered_set<char> freq;
       	//         freq.insert(s[i]);
       	//         int len = 1;
       	//         for(int j=i+1;j < n;j++){
       	//             if(freq.find(s[j])==freq.end()){
       	//                 len++;
       	//                 freq.insert(s[j]);
       	//             }else   break;
       	//         }
       	//         ans = max(ans,len);
       	//     }
       	//     return ans;

       	//SLIDING WINDOW  - TIME COMPLEXITY O(2n)
       	//                  SPACE COMPLEXITY O(m)  	//size of array

        int store[256] = { 0 };	//array to store the occurences of all the characters
    int l = 0;	//left pointer
    int r = 0;	//right pointer
    int ans = 0;	//initializing the required length as 0

    while(r < s.length()){
        store[s[r]]++;	//increment the count of the character present in the right pointer 

        while(store[s[r]] > 1)	//if the occurence become more than 1 means the char is repeated
        {
            store[s[l]]--;	//reduce the occurence of temp as it might be present ahead also in thestring
            l++;	//contraction of the present window till the occurence of the 't' char becomes 1
        }

        ans = max(ans, r - l + 1);	//As the index starts from 0, ans will be (right pointer-left pointer + 1)
        r++;	// now will increment the right pointer 
    }
    return ans;
}
};