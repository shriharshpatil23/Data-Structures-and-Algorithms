bool cmp(vector<int> a , vector<int> b){
    if(a[0]==b[0])   return a[1]<b[1];  //if height equal sort according to Rank
    
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;                //store the ans
        sort(people.begin(),people.end(),cmp);          //    sort the vector
        
        for(auto x : people){
            ans.insert(ans.begin()+x[1],x);     //inserting at right Position
        }
        return ans;
    }
};