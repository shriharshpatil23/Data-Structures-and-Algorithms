class Solution {
public:
    int strStr(string haystack, string needle) {
       int len = needle.size();
        if(len == 0)
        {
            return 0;
        }
        int n = haystack.size();
        for(int i = 0; i+len-1 < n; i++)
        {
            //Checking if there is a substring equal to the string needle in haystack
            if(haystack.substr(i,len) == needle)
            {
                return i;
            }
        }
        return -1;
        
    }
};