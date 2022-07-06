class Solution {
public:
    string countAndSay(int n) {
          if(n==1)
            return "1";
        string say = countAndSay(n-1);
        string res="";
        int val = say[0]-'0';
        int count=1;
        for(int i=1;i<say.length();i++)
        {
            if(say[i]-'0'==val)
                count++;
            else
            {
                res+=to_string(count);
                res+=to_string(val);
                count=1;
                val=say[i]-'0';
            }
        }
        res+=to_string(count);
        res+=to_string(val);
        return res;
    }
};