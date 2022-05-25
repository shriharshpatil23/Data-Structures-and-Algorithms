class Solution {
   static bool cmp (vector<int> i, vector<int> j) {
    if (i[0] == j[0])
        return i[1] > j[1];
    return i[1] < j[1];
}
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sorting by height & if we encounter same height
        // sort by descending order of width
        // sort(envelopes.begin(), envelopes.end(), cmp);
        
        // e.g. -> env => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        // sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
        // Now, we only need to care about width
        // So, as of now we only need to look upon v[i][1]
        // [ 6, 1, 8, 5, 7, 3, 8 ]
        
        // Now, we can only put envolop a in envolop b another if width of a is
        // less than width of b, or we can say we need an envolop whose width
        // is just greater than envolop a ( height we have already handled )
        // So, we can think of lower_bound and Longest Increasing Subsequence
        
        // because we have sorted all envolopes of a particular height
        // by descending order of width, one envolope will not interfare with 
        // another envolop of same height, if we apply lower_bound
        // i.e. first elem greater than equal to itself in lis
        
        if (envelopes.empty()) return 0;
    sort(envelopes.begin(), envelopes.end(),[](vector<int> &a,vector<int> &b){ //& is used for call by reference
        return (a[0]<b[0] || (a[0]==b[0] && (a[1]>b[1])));
    });
    vector<int> dp;
    
    for(auto i:envelopes)
    {
        auto itr=lower_bound(dp.begin(),dp.end(),i[1]);
        
        if(itr==dp.end())
        {
            dp.push_back(i[1]);
        }
        else if(i[1]<*itr)
        {
            *itr=i[1];
        }
    }
    return dp.size();
    } 
};