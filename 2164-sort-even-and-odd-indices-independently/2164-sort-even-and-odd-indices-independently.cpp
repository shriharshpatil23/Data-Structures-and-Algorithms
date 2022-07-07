class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd,even;
        for(int i=0;i<n;i++){
            if(i%2==0)  even.push_back(nums[i]);
            else    odd.push_back(nums[i]);
        }
        int len1 = even.size();
        int len2 = odd.size();
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int> ());
        vector<int> ans(n);
        int i =0;
        int j=0;
        int k=0;
        while(i<len1 && j<len2){
            ans[k++]=even[i++];
            ans[k++]=odd[j++];
        }
        while(i<len1)   ans[k++]=even[i++];
        
        while(j<len2)   ans[k++]=odd[j++];
        
        return ans;
    }
};