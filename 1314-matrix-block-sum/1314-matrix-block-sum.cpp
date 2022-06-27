class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
   
        int presum[101][101],m=mat.size(),n=mat[0].size();
        
        //Step 1 Make a prefix sum matrix
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0)
                {
                    if(i==0 and j==0)
                        presum[i][j]=mat[i][j];
                    
                    else if(i==0)
                        presum[i][j]=presum[i][j-1]+mat[i][j];
                    
                    else if(j==0)
                        presum[i][j]=presum[i-1][j]+mat[i][j];
                }
                
                else
                presum[i][j]=mat[i][j]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
            }
        }
        
        //Step 2 Form the answer
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int row=(i+k>=m)?m-1:i+k;
                int col=(j+k>=n)?n-1:j+k;
                
                
//Bete aise smjh nahi ayega copy me dry run kroo !!! Bohat pyara aur esy question ek hi baar me submit
                ans[i][j]=presum[row][col];
                
                if(i-k-1>=0)
                    ans[i][j]-=presum[i-k-1][col];
                
                if(j-k-1>=0)
                    ans[i][j]-=presum[row][j-k-1];
                
                 if(i-k-1>=0 and j-k-1>=0)
                    ans[i][j]+=presum[i-k-1][j-k-1];
            }
        }
        
        return ans;
    }
};