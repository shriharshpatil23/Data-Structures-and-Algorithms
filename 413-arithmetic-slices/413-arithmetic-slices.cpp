class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
//        O(N*N approach )
//         int n = nums.size();
//         if(n<3) return 0;
        
//         int diff, count = 0;
//         for(int i=0;i<n-2;i++){
//             diff = nums[i+1]-nums[i];
//             for(int j = i+2;j<n;j++){
//                 if(diff == nums[j]-nums[j-1]){
//                     count ++;
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return count;
        int n = nums.size(), count =0;
        if(n<3) return 0;
        int Totalcount = 0 , diff = 0 ;
        int prev_diff = nums[1]-nums[0];
        
        for(int i=1;i<=n-2;i++){
            int diff = nums[i+1]-nums[i];
            if(prev_diff==diff){
                count ++;
            }else{
                prev_diff = diff;
                count = 0;
            }
            Totalcount += count;
        }
        return Totalcount;
    }
};