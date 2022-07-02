//#DEFINE MOD 1000000007;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hz, vector<int>& vz) {
        const unsigned int M = 1000000007;
        hz.push_back(0);
        vz.push_back(0);
        hz.push_back(h);
        vz.push_back(w);
        long ht = 0;
        long vt = 0;
        int n1 = hz.size();
        int n2 = vz.size();
        sort(hz.begin(),hz.end());
        sort(vz.begin(),vz.end());
        for(int i=1;i<n1;i++){
            long tmp = hz[i]-hz[i-1];
               ht = max(ht,tmp );
        }
        for(int i=1;i<n2;i++){
            long tmp = vz[i]-vz[i-1];
               vt = max(vt, tmp);
        }
        int ans = 0;
        ans = ((ht%M)*(vt%M))%M;
        return ans;
    }
};