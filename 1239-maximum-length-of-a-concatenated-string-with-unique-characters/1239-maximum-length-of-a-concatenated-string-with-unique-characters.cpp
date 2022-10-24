class Solution {
public:
    //Used to map characters
    int m[26];
    
    
    void helper(vector<string>& v,int st,int n,int &ans)
    {
        //Used to store temp ans upto index st in vector v.
        int res=0;
        for(int i=0;i<26;i++)
        {
            //If any character appears more than 1 time, just return and try next possibilities
            if(m[i]>1)return;
            if(m[i]==1)res++;
        }
        
        //Updating ans
        ans=max(ans,res);
        for(int i=st;i<n;i++)
        {
            //Including string v[i] and then calling the function again with starting index as i+1.
            for(auto x:v[i])m[x-'a']++;
            helper(v,i+1,n,ans);
            //After the function call excluding string v[i]
            for(auto x:v[i])m[x-'a']--;
        }
    }
    
    int maxLength(vector<string>& arr) {
        memset(m,0,sizeof(m));
        int ans=0;
        helper(arr,0,arr.size(),ans);
        return ans;
    }
};