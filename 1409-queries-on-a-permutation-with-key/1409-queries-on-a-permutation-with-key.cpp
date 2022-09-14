class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> arr(m);
        vector<int> ans;
        for(int i=0;i<m;i++)    arr[i]=i+1;
        
        for(int i=0;i<queries.size();i++){
            int pos = find(arr.begin(),arr.end(),queries[i])-arr.begin();
            ans.push_back(pos);
            arr.erase(arr.begin()+pos);
            arr.insert(arr.begin(),queries[i]);
        }
        return ans;
    }
};