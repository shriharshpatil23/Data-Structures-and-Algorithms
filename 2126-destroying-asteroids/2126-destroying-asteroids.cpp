class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        long long mass = m;
        int n = ast.size();
        for(int i=0;i<n;i++){
            if(mass>=ast[i]){
                mass += ast[i];
            }else{
                return false;
            }
        }
        return true;
    }
};