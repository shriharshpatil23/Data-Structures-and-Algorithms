class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> s;
        vector<string> ans;
        int minSum = INT_MAX;
        for(int i=0;i<list1.size();i++){
            s[list1[i]]=i+1;
        }
        for(int j=0;j<list2.size();j++){
            if(s[list2[j]]>0){
                if(s[list2[j]] + j <minSum){
                    ans = {};
                    ans.push_back(list2[j]);
                    minSum = s[list2[j]] + j;
                }else   if(s[list2[j]] + j == minSum){
                    ans.push_back(list2[j]);
                }
            }   
        }
        return ans;
    }
};