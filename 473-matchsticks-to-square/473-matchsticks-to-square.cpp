class Solution {
public:
      bool backtrack(vector<int>& ms,vector<bool> &vis,int target,int curr_sum,int idx,int k)
    {
        if(k==1)
            return true;
        if(idx>=ms.size()||ms[idx]>target)
            return false;
        if(curr_sum==target)
        {
            return backtrack(ms,vis,target,0,0,k-1);
        }
        for(int i=idx;i<ms.size();i++)
        {
            if(!vis[i])
            {
                if(ms[i]+curr_sum<=target)
                {
                    vis[i]=true;
                    if(backtrack(ms,vis,target,ms[i]+curr_sum,i+1,k))
                        return true;
                    vis[i]=false;
                }
            }
        }
        return false;
    }
    bool makesquare(vector<int>& ms)
    {
        int sum=0;
        sum=accumulate(ms.begin(),ms.end(),sum);
        if(ms.size()<4||sum%4!=0)
            return false;
        vector<bool> vis(ms.size(),false);
        return backtrack(ms,vis,sum/4,0,0,4);
    }
};